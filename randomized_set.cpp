// Implement the RandomizedSet class:

// RandomizedSet() Initializes the RandomizedSet object.
// bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
// bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
// int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
// You must implement the functions of the class such that each function works in average O(1) time complexity.

#include <unordered_set>
#include <random>
#include <iostream>
#include <unordered_map>
#include <vector>

class RandomizedSet1
{
    std::unordered_set<int> data_;

public:
    bool insert(int value)
    {
        auto ret = data_.insert(value);
        return ret.second;
    }

    bool remove(int value)
    {
        auto ret = data_.erase(value);
        return ret > 0;
    }

    int getRandom()     // Oo(n)
    {
        int size = data_.size();
        
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> distrib(0, size-1);

        int index = distrib(gen);
        // return *(data_.begin() + index);     // hashset not indexable.

        auto iter = data_.begin();
        while(index>0)
        {
            iter++;
            --index;
        }

        return *iter;
    }
};


class RandomizedSet
{
    std::unordered_map<int, int> hash_data_;
    std::vector<int> data_;

public:
    bool insert(int value)
    {
        auto ret = hash_data_.find(value);

        if(ret == hash_data_.end())
        {
            hash_data_.emplace(value, data_.size());
            data_.push_back(value);
            return true;
        }
        
        return false;
    }

    bool remove(int value)
    {
        auto ret = hash_data_.find(value);

        if(ret == hash_data_.end())
        {
            return false;
        }
        
        int swap = data_.back();
        auto iter = hash_data_.find(swap);
        data_[ret->second] = swap;
        iter->second = ret->second;
        hash_data_.erase(ret);
        data_.pop_back();
        return true;
    }

    int getRandom()
    {
        int size = data_.size();
        
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> distrib(0, size-1);

        int index = distrib(gen);
        return data_[index];
    }
};


int main ()
{
    RandomizedSet randomizedSet;
    std::cout << std::boolalpha << randomizedSet.insert(1) << std::endl; // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    std::cout << std::boolalpha << randomizedSet.remove(2) << std::endl; // Returns false as 2 does not exist in the set.
    std::cout << std::boolalpha << randomizedSet.insert(2) << std::endl; // Inserts 2 to the set, returns true. Set now contains [1,2].
    std::cout << randomizedSet.getRandom() << std::endl; // getRandom() should return either 1 or 2 randomly.
    std::cout << std::boolalpha << randomizedSet.remove(1) << std::endl; // Removes 1 from the set, returns true. Set now contains [2].
    std::cout << std::boolalpha << randomizedSet.insert(2) << std::endl; // 2 was already in the set, so return false.
    std::cout << randomizedSet.getRandom() << std::endl; // Since 2 is the only number in the set, getRandom() will always return 2.

    return 0;
}