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

// void ThreeSum_index()
// {
//     for (int i = 0; i < nums.size()-1; ++i)
//     {
//         int value_ = nums[i];
        
//         // find two sums equals to -value_

//         std::unordered_map<int, int> maps;
//         maps.emplace(-value_-nums[i+1], i+1);
//         for(int j = i+2; j < nums.size(); ++j)
//         {
//             auto iter = maps.find(nums[j]);
//             if (iter != maps.end())
//             {
//               results.push_back({nums[i], nums[iter->second], nums[j]});
//             }
//             maps.emplace(-value_-nums[j], j);
//         }
//     }
// }

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 22;
    std::pair<const int, const int> match = findTwoSum(target, nums);
    std::cout << match.first << "," << match.second << std::endl;
    return 0;
}