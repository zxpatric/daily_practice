// Input:
// n=3
// edges=[[0,1], [0,2]]

// Output:
// 1

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> Pair;
typedef std::vector<Pair> PairList;

void deep_search(const int seed, const PairList &edges, std::vector<bool>& visited)
{
    // find all the edges from the seed and then do the deep search
    std::vector<PairList::const_iterator> iters;
    for (PairList::const_iterator iter = edges.cbegin(); iter != edges.cend(); ++iter)
    {
        PairList::const_iterator find_iter = std::find_if(iter, edges.cend(), [seed](const Pair &pair) {
            return pair.first == seed;
        });
        if (find_iter != edges.end())
        {
            iters.push_back(find_iter);
            iter = find_iter;
        }
    }

    visited.at(seed) = true;

    if (iters.empty())
    {
        return;
    }
    else
    {
        for (auto iter : iters)
        {
            if (!visited[iter->second])
            {
                deep_search(iter->second, edges, visited);
            }
        }
    }
}

int countComponents(int n, const PairList &edges)
{
    std::vector<bool> visited(n, false);

    const int seed = 0; 

    deep_search(seed, edges, visited);

    return std::count_if(visited.begin(), visited.end(), [](bool val) {
        return val;
    });
}
        
int main ()
{
    const int num_nodes = 5;
    PairList list;
    list.push_back(std::make_pair(0, 1));
    list.push_back(std::make_pair(0, 2));
    // list.push_back(std::make_pair(2, 3));
    list.push_back(std::make_pair(3, 4));

    std::cout << "number of nodes: " << num_nodes << " and the connect nodes are " << countComponents(num_nodes, list) << std::endl;
    return 0;
}