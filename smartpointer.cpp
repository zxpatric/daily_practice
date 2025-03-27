#include <memory>
#include <iostream>

int std_func()
{
    std::unique_ptr<int> int_uptr(new int());
    *int_uptr = 10;
    // int* int_ptr = int_uptr.release();
    std::cout << *int_uptr << std::endl;
    int* int_ptr = int_uptr.get();
    *int_ptr = 11;
    // int_uptr.reset();
    std::cout << *int_uptr << std::endl;

    std::shared_ptr<int> int_sptr(int_ptr);
    std::cout << *int_sptr << std::endl;
    std::cout << int_sptr.use_count() << std::endl;
    int_uptr.release(); 
    // can't use reset() since the object will be double freed.

    return 0;
}


template <typename T>
class _unique_ptr final
{
private:
    T* ptr_;

public:    
    _unique_ptr (T* ptr) : ptr_(ptr)
    {

    }

    ~_unique_ptr ()
    {
        reset();
    }

    _unique_ptr(const _unique_ptr& uptr) = delete;
    _unique_ptr& operator=(const _unique_ptr& uptr) = delete;

    _unique_ptr(_unique_ptr&& uptr)
    {
        this->reset();
        this->ptr_ = uptr.get();
        uptr.release();
    }
    _unique_ptr& operator=(_unique_ptr&& uptr)
    {
        this->reset();
        this->ptr_ = uptr.get();
        uptr.release();
        return *this;
    }


    T& operator*()
    {
        return *ptr_;
    }

    T* operator->()
    {
        return ptr_;
    }

    T* get()
    {
        return ptr_;
    }

    void release()
    {
        ptr_ = nullptr;
    }

    void reset(T* new_ptr_=nullptr)
    {
        if (ptr_)
        {
            delete ptr_;
            ptr_ = nullptr;
        }

        this->ptr_ = nullptr;
    }
};


class ReferenceCount
{
    int count_;

public:
    ReferenceCount () : count_(0) {}

    void add_ref () {
        ++count_;
    }

    void release ()
    {
        --count_;
    }

    inline int use_count () {
        return count_;
    }
};

struct TestClass
{
    bool& deleted_;

    ~TestClass()
    {
        std::cout << "Test Class is released" << std::endl;
        deleted_ = true;
    }
};


template <typename T>
class _shared_ptr final
{
    T* ptr_;
    ReferenceCount* ref_;    
public:
    _shared_ptr() : ptr_(nullptr), ref_(new ReferenceCount())
    {

    }

    _shared_ptr(T* ptr) : ptr_(ptr), ref_(new ReferenceCount())
    {
        ref_->add_ref();
    }

    ~_shared_ptr()
    {
        ref_->release();
        if(ref_->use_count() == 0)
        {
            std::cout << "Shared memory is released" << std::endl;
            delete ptr_;
            delete ref_;
        }
    }

    _shared_ptr (const _shared_ptr& sptr)
    {
        this->ptr_ = sptr.ptr_;
        this->ref_ = sptr.ref_;
        this->ref_->add_ref();
    }

    _shared_ptr& operator= (const _shared_ptr& sptr)
    {
        this->reset();
        this->ptr_ = sptr.ptr_;
        this->ref_ = sptr.ref_;
        this->ref_->add_ref();

        return *this;
    }

    _shared_ptr (_shared_ptr&& sptr)
    {
        this->reset();
        this->ptr_ = sptr.ptr_;
        this->ref_ = sptr.ref_;
        sptr.ptr_ = nullptr;
        sptr.ref_ = nullptr;
    }

    _shared_ptr& operator= (_shared_ptr&& sptr)
    {
        this->reset();
        this->ptr_ = sptr.ptr_;
        this->ref_ = sptr.ref_;
        sptr.ptr_ = nullptr;
        sptr.ref_ = nullptr;

        return *this;
    }

    T& operator*()
    {
        return *ptr_;
    }

    T* operator->()
    {
        return ptr_;
    }

    T* get()
    {
        return ptr_;
    }

    void reset(T* new_ptr_=nullptr)
    {
        ref_->release();
        if(ref_->use_count() == 0)
        {
            delete ptr_;
            ptr_ = nullptr;
            delete ref_;
            ref_ = nullptr;
        }

        if(new_ptr_)
        {
            ptr_ = new_ptr_;
            ref_ = new ReferenceCount();
        }
    }

    int use_count() const
    {
        if (ref_)
        {
            return ref_->use_count();
        }

        return 0;
    }
};

template <typename T>
class _weak_ptr final
{
    const _shared_ptr<T>*  ref_sptr_;
    const _weak_ptr<T>*  ref_wptr_;

public:
    _weak_ptr(_shared_ptr<T>&  ref_sptr) : ref_sptr_(&ref_sptr), ref_wptr_(nullptr)
    {}

    _weak_ptr(_weak_ptr<T>&  ref_wptr) : ref_wptr_(&ref_wptr), ref_sptr_(nullptr)
    {}

    _weak_ptr& operator=(const _weak_ptr& wptr)
    {
        ref_wptr_ = &wptr;
        return *this;
    }

    _shared_ptr<T> lock() const noexcept
    {
        if (ref_sptr_!=nullptr)
        {
            return _shared_ptr(*ref_sptr_);
        }

        if (ref_wptr_!=nullptr)
        {
            return ref_wptr_->lock();
        }

        return _shared_ptr<T>();
    }

    bool expired () const
    {
        return (ref_sptr_!=nullptr && ref_sptr_->use_count()==0) 
        || (ref_wptr_!=nullptr && ref_wptr_->expired()
        || (ref_sptr_==nullptr && ref_wptr_==nullptr));
    }

    void reset()
    {
        ref_sptr_ = nullptr;
        ref_wptr_ = nullptr;
    }
};

#include <cassert>

int main()
{
    _unique_ptr<int> int_uptr(new int());
    *int_uptr = 10;
    // int* int_ptr = int_uptr.release();
    std::cout << *int_uptr << std::endl;
    int* int_ptr = int_uptr.get();
    *int_ptr = 11;
    // int_uptr.reset();
    std::cout << *int_uptr << std::endl;
    // int_uptr.reset();

    _shared_ptr<int> int_sptr(int_ptr);
    std::cout << *int_sptr << std::endl;
    *int_uptr = 12;
    std::cout << int_sptr.use_count() << " " << *int_sptr << std::endl;
    int_uptr.release(); 

    _weak_ptr<int> int_wptr(int_sptr);
    std::cout << int_wptr.expired() << std::endl;
    _shared_ptr<int> temp_sptr = int_wptr.lock();
    std::cout << temp_sptr.use_count() << std::endl;
    // int_wptr.reset();
    

    bool deleted = false;
    {
        _shared_ptr<TestClass> test_sptr(new TestClass{.deleted_ = deleted});
    }
    assert(deleted);

    return 0;
}