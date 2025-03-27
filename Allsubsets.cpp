#include <vector>
#include <iostream>
#include <math.h>

void print_subsets(int& total, std::vector<int>& values, std::vector<int>& combs, int start, int index) {
    int value_size = values.size();
    int comb_size = combs.size();
    
    if(index == comb_size)
    {
        for (auto co : combs)
        {
            std::cout << co << " ";
        }
        std::cout << std::endl;
        total++;
        return;
    }

    for(int i=start; comb_size - index <= value_size - i; ++i)
    {
        combs[index] = values[i];
        print_subsets (total, values, combs, i+1, index+1);
    }
}


int main()
{
    std::vector<int> values = {1, 2, 3, 4, 5};

    int total = 0;
    for (int i=0; i<=values.size(); ++i)
    {
        std::vector<int> combs(i);
        print_subsets(total, values, combs, 0, 0);
    }

    std::cout << "Total " << total << " sequences and theoratical toal is " << std::pow(2, values.size()) << std::endl;

    return 0;
}