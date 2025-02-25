#include <vector>
#include <iostream>

int main()
{
    std::vector<int> elements = {1,1,1,2,2,3};
    // std::vector<int> elements =  {0,0,1,1,1,1,2,3,3,3,3};

    int current_value = *elements.begin();
    int count = 0;

    std::vector<int>::iterator copy_to_;
    for(std::vector<int>::iterator cur_ = elements.begin(); cur_ != elements.end(); )
    {
        if (current_value == *cur_)
        {
            cur_++;
            count++;
            if (count == 2)
            {
                copy_to_ = cur_;
            }
        }
        else
        {
            current_value = *cur_;
            if(count > 2)
            {
                std::copy(cur_, elements.end(), copy_to_);
                elements.resize(elements.size() - (cur_ - copy_to_));
                cur_ = copy_to_;
            }
            count = 0;
        }
    }
    if(count > 2)
    {
        elements.resize(elements.size() - (count - 2));
    }

    for (auto el : elements)
    {
        std::cout << el << ",";       
    }
    std::cout << std::endl;

    return 0;

}