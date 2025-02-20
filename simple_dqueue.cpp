#include <vector>
#include <iostream>

// This SimpleDQueue implementes a fixed size dqueue
template <typename T>
struct SimpleDQueue
{
    std::vector<T> data_storage_;
    int data_size_;

    SimpleDQueue(int fixed_size){
        data_storage_.reserve(fixed_size);
        data_size_ = fixed_size;
    }

    void push_back(T val)
    {
        if (data_storage_.size() == data_size_)
        {
            throw std::out_of_range("Queue is full");
        }
        data_storage_.push_back(val);
    }

    void pop_front()
    {
        data_storage_.erase(data_storage_.begin());
    }

    void push_front(T val)
    {
        if (data_storage_.size() == data_size_)
        {
            throw std::out_of_range("Queue is full");
        }
        data_storage_.insert(data_storage_.begin(), val);
    }

    void pop_back()
    {
        if (data_storage_.size() > 0)
        {
            data_storage_.pop_back();
        }
    }

    void print()
    {
        std::cout << "Queue size: " << data_storage_.size() << std::endl;
        for (auto &val : data_storage_)
        {
            std::cout << val << ",";
        }
        std::cout << std::endl;
    }
};

int main()
{
    int count = 10;
    SimpleDQueue<int> a_dqueue(count);

    for (size_t i = 0; i <= count ; i++)
    {
        try
        {
            a_dqueue.push_back(i);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << " when pushing a value " << i << std::endl;
        }
    }
    a_dqueue.print();

    a_dqueue.pop_front();
    a_dqueue.print();
    a_dqueue.pop_back();
    a_dqueue.print();


    for (size_t i = 0; i < count ; i++)
    {
        a_dqueue.pop_back();
    }

    a_dqueue.print();

    return 0;
}