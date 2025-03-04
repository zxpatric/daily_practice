#include <vector>
#include <iostream>

bool is_palindrome(std::string str)
{
    int len_ = str.length();
    for (int i=0, j=len_-1; i<=j; i++,j--)
    {
        if(str[i] != str[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // std::string str = "madam";
    std::string str = "madaam";

    std::cout << is_palindrome(str) << std::endl;

    return 0;
}  