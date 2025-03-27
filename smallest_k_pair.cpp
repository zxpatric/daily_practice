#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> KSmallestPairs(vector<int>& list1, vector<int>& list2, int k) {
    
    // Replace this placeholder return statement with your code
    int list_size = list1.size();
    
    using ValuePair = std::pair<int, std::pair<int, int>>;
    auto cmp = [](ValuePair a, ValuePair b) {return a.first > b.first;};
    //std::priority_queue<ValuePair, std::vector<ValuePair>, std::greater<ValuePair>> value_pair_heap;
    std::priority_queue<ValuePair, std::vector<ValuePair>, decltype(cmp)> value_pair_heap(cmp);
    
    std::vector<std::vector<int>> pairs;
    
    for(int i=0; i<std::min(list_size,k); i++)
    {
//      auto index_pair = std::make_pair(i, 0);
//      auto pair_value = std::make_pair(list1[i]+list2[0], index_pair);
//      value_pair_heap.push(pair_value);
      value_pair_heap.push({list1[i]+list2[0], {i, 0}});
    }
    
    int count = 0;
    while(!value_pair_heap.empty() && count<k)
    {
      auto value_pair = value_pair_heap.top();
      int i = value_pair.second.first;
      int j = value_pair.second.second;
      value_pair_heap.pop();
      
      pairs.push_back({list1[i], list2[j]});
      count++;
      
      ++j;
      if(j<list2.size())
      {
        auto pair_value = std::make_pair(list1[i]+list2[j], std::make_pair(i, j));
        value_pair_heap.push(pair_value);
      }
    }
 
    return pairs;   
}