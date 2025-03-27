#include <vector>
#include <iostream>

void heap_permutation (int& total, std::vector<int>& nums, int size)
{
    if(size == 1)
    {
        for (auto co : nums)
        {
            std::cout << co << " ";
        }
        std::cout << std::endl;
        total++;
        return;
    }

    for (int i=0; i<size; ++i)
    {
        heap_permutation(total, nums, size-1);

        if(size%2==1)
        {
            //swap the nums.current last  with nums.front
            //since the heap_permutation(total, nums, size-1) will keep rotating the new value to front.
            std::swap(nums.front(), nums[size-1]);
        }
        else
        {
            //swap the nums.current last with nums[i]
            //keep rotating the value to the last.
            std::swap(nums[i], nums[size-1]);
        }
    }
}

int factorial(int n)
{
    if (n<0)
    {
        // undefined but return 0
        return 0;
    }
    else if(n==0)
    {
        return 1;
    }
    else
    {
        return factorial(n-1)*n;
    }
}

int main()
{
    std::vector<int> values = {1, 2, 3, 4};
    int size = values.size();
    int total = 0;
    heap_permutation(total, values, size);

    std::cout << "Total " << total << " sequences and theoratical toal is " << factorial(values.size()) << std::endl;

    return 0;
}