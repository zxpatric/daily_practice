#include <iostream>
#include <vector>

std::vector<std::string> letterCombinations(const std::vector<std::vector<char>>& mapping, const std::string& digits)
{
    std::vector<std::string> result;
    if (digits.empty()) return result;

    char digit = digits[0];
    std::vector<std::string> next_result = std::move(letterCombinations(mapping, digits.substr(1)));

    if (next_result.empty())
    {
        for (char c : mapping[digit - '2'])
        {
            result.push_back(std::string(1, c));
        }
    }
    else
    {
        for (char c : mapping[digit - '2'])
        {
            for (const std::string& str : next_result)
            {
                result.push_back(c + str);
            }
        }
    }

    return result;
}

int main ()
{
    std::vector<std::vector<char>> mapping = 
    {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };

    std::string digits = "234893";

    std::vector<std::string> result = letterCombinations(mapping, digits);
    std::cout << "Combinations for " << digits << " Total " << result.size() << " :" << std::endl;
    for (const auto& str : result) {
        std::cout << str << std::endl;
    }
}