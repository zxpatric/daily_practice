#include <vector>
#include <iostream>
#include <limits>

bool can_jump_out (const std::vector<int>& nums)
{
    if(nums.empty())
        return true;

    std::vector<bool> can_out(nums.size());
    can_out.at(nums.size()-1) = true;
    for (int i = nums.size()-2; i >=0 ; i--)
    {
        for(int j = 1; j <= nums.at(i); ++j)
        {
            if(can_out.at(i+j))
            {
                can_out.at(i) = true;
                break;
            }
        }
    }

    return can_out[0];
}

int minimum_jump(const std::vector<int>& nums)
{
    if(nums.empty())
        return 0;
    
    std::vector<int> steps_out(nums.size());
    steps_out.at(nums.size()-1) = 0;
    for (int i = nums.size()-2; i >=0 ; i--)
    {
        int minimum_step = std::numeric_limits<int>::max();
        for(int j = 1; j <= nums.at(i); ++j)
        {    
            if((i+j)>=(nums.size()-1))
            {
                minimum_step = 1;
            }
            else if(steps_out.at(i+j) > 0)
            {
                minimum_step = std::min(minimum_step, steps_out.at(i+j) + 1);
            }
        }
        if (minimum_step == std::numeric_limits<int>::max())
            steps_out.at(i) = -1;
        else
            steps_out.at(i) = minimum_step;
    }

    // for (auto el : steps_out)
    // {
    //     std::cout << el << ",";       
    // }
    // std::cout << std::endl;

    return steps_out[0];
}

int main()
{
    std::vector<int> nums = {2,3,1,1,4};

    // std::vector<int> nums = {3,2,1,0,4};

    // std::cout << can_jump_out (nums) << std::endl;

    std::cout << minimum_jump (nums) << std::endl;

    return 0;

}    