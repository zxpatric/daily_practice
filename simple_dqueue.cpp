#include <vector>
#include <iostream>

using namespace std;

// This SimpleDQueue implementes a fixed size dqueue
template <typename T>
struct SimpleDQueue
{
    vector<T> m_data;
    int m_fixed_size;

    SimpleDQueue(int fixed_size){
        m_data.reserve(fixed_size);
        m_fixed_size = fixed_size;
    }

    void push_back(T val)
    {
        if (m_data.size() == m_fixed_size)
        {
            throw std::out_of_range("Queue is full");
        }
        m_data.push_back(val);
    }

    void pop_front()
    {
        m_data.erase(m_data.begin());
    }

    void push_front(T val)
    {
        if (m_data.size() == m_fixed_size)
        {
            throw std::out_of_range("Queue is full");
        }
        m_data.insert(m_data.begin(), val);
    }

    void pop_back()
    {
        if (m_data.size() > 0)
        {
            m_data.pop_back();
        }
    }

    void print()
    {
        cout << "Queue size: " << m_data.size() << endl;
        for (auto &val : m_data)
        {
            cout << val << ",";
        }
        cout << endl;
    }
};

int main()
{
    int count = 10;
    SimpleDQueue<int> a_dqueue(count);

    for (size_t i = 0; i <= count ; i++)
    {
        /* code */
        try
        {
            /* code */
            a_dqueue.push_back(i);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << " when pushing a value " << i << endl;
        }
    }
    a_dqueue.print();

    a_dqueue.pop_front();
    a_dqueue.print();
    a_dqueue.pop_back();
    a_dqueue.print();


    for (size_t i = 0; i < count ; i++)
    {
        /* code */
        a_dqueue.pop_back();
    }

    a_dqueue.print();

    return 0;
}