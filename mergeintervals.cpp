#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> Pair;
typedef std::vector<Pair> PairList;

bool is_overlap_sorted(const Pair &a, const Pair &b)
{
    // didn't get the b.end >= a.first && b.end <= a.second into consider since the pairs are sorted by .first.
    return a.first <= b.first && a.second >= b.first;
}


PairList merge_intervals_sorted(const PairList &list)
{
    PairList new_list;
    new_list.reserve(list.size());
    for (auto &pair : list)
    {
        // std::cout << pair.first << "," << pair.second << std::endl;
        if (new_list.empty())
        {
            new_list.push_back(pair);
        }
        else
        {
            Pair &last = new_list.back();
            if (is_overlap_sorted(last, pair))
            {
                last.second = std::max(last.second, pair.second);
            }
            else
            {
                new_list.push_back(pair);
            }
        }
    }
    return new_list;
}


int main   ()
{
    PairList a_list;
    a_list.push_back({1, 2});
    a_list.push_back({3, 4});
    a_list.push_back({1, 6});
    a_list.push_back({7, 8});
    a_list.push_back({13, 16});

    // O(nlog(n)) sort
    std::sort(a_list.begin(), a_list.end(), [](const Pair &a, const Pair &b) {
        return a.first < b.first;
    });

    // O(n) merge
    PairList new_list = std::move(merge_intervals_sorted(a_list));
    for(auto [l, r] : new_list)
    {
        std::cout << l << "," << r << std::endl;
    }

    return 0;
}