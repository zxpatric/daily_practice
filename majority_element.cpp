#include <vector>
#include <iostream>
#include <unordered_map>
#include <limits>


int main   ()
{

    std::vector<int> elements = {3,2,3};

    std::unordered_map<int, int> counts;

    int max_count = 0;
    int the_value = std::numeric_limits<int>::min();

    for (auto el_ : elements)
    {
        std::unordered_map<int, int>::iterator iter = counts.find(el_);
        int new_count = 0;
        if (iter != counts.end())
        {
            iter->second += 1;
            new_count = iter->second;
        }
        else
        {
            counts.emplace(el_, 1);
            new_count = 1;
        }

        if (new_count > max_count)
        {
            max_count = new_count;
            the_value = el_;
        }
    }

    std::cout << "The value " << the_value << " is of maximum count " << max_count << std::endl;

    return 0;
}