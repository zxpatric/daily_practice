#include <vector>
#include <iostream>


int main   ()
{
    std::vector<int> array0 = {1,2,3};
    std::vector<int> array1 = {2,5,6};

    std::vector<int> results;
    std::vector<int>::iterator iter0 = array0.begin();
    std::vector<int>::iterator iter1 = array1.begin();
    while (iter0 != array0.end() && iter1 != array1.end())
    {
        if(*iter0 < *iter1)
        {
            results.push_back(*iter0);
            ++iter0;
        }
        else
        {
            results.push_back(*iter1);
            ++iter1;
        }
    }

    for(;iter0!=array0.end();++iter0)
    {
        results.push_back(*iter0);
    }

    for(;iter1!=array1.end();++iter1)
    {
        results.push_back(*iter1);
    }

    for (auto a : results)
    {
        std::cout << a << std::endl;       
    }

    return 0;
}