#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::pair<const int, const int> findTwoSum (int target, const std::vector<int>& nums)
{
    std::unordered_map<int, int> value_map;
    for (int i=0; i<nums.size(); ++i)
    {
        int compliment = target - nums[i];
        auto iter = value_map.find(compliment);
        if( iter != value_map.end())
        {
            return std::make_pair(iter->second, i);
        }
        value_map.insert({nums[i], i});
    }
    return std::make_pair(-1, -1);
}

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 22;
    std::pair<const int, const int> match = findTwoSum(target, nums);
    std::cout << match.first << "," << match.second << std::endl;
    return 0;
}