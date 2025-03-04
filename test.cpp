#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

// bool ValidWordAbbreviation(std::string word, std::string abbr) {

//     // Replace the following return statement with your code
//     int i = 0, j=0;
//     while(i < word.length() && j<abbr.length())
//     {
//       if (abbr[j] == word[i])
//       {
//         i++;
//         j++;
//       }
//       else if(std::isdigit(abbr[j]))
//       {
//         if(abbr[j]=='0')
//             return false;

//         // find continuous digits and convert them to a number
//         int k = j;
//         for(;k<abbr.length();++k)
//         {
//           if(!std::isdigit(abbr[k]))
//             break;
//         }
        
//         i+= atoi(abbr.substr(j, k-j).c_str());
//         j=k;
//       }
//       else
//       {
//         return false;
//       }
//     }
    
//     return i == word.length() && j == abbr.length();
// }

std::vector<int> SortColors(std::vector<int> colors) {

    // Write your code here
    
    // sort the red to the left
    int i = 0;
    int j = colors.size() - 1;
    while (i<j)
    {
      while (i<j && colors[i] == 0)
        i++;
      while (i<j && colors[j] != 0)
        j--;
      if (i>=j)
        break;
      //colors[j] = colors[i];
      //colors[i] = 0;
      std::swap(colors[i], colors[j]);
      i++;
      j--;
    }
    
    // sort the white to the left
    j = colors.size() - 1;
    while (i<j)
    {
      while (i<j && colors[i] == 1)
        i++;
      while (i<j && colors[j] != 1)
        j--;
      if (i>=j)
        break;
//      colors[j] = colors[i];
//      colors[i] = 1;
      std::swap(colors[i], colors[j]);
      i++;
      j--;
    }    
    
    return colors;
}

// int main()
// {

//     // ValidWordAbbreviation("internationalization", "13iz4n");
//     // std::cout << ValidWordAbbreviation("bcnwrhcp" , "08drbff0") << std::endl;

//     // std::vector<int> colors = {2,1,1,0,0};
//     std::vector<int> colors = {0,0,2,2,2,2,1,1,0,0,1,0,2,0};
//     colors = SortColors (colors);
//     for (auto c : colors)
//     {   
//         std::cout << c << ",";
//     }
//     std::cout << std::endl;
// }

// int main()
// {
//     std::string s1 = "Test";
// //  std::string&& r1 = s1;           // error: can't bind to lvalue
 
//     const std::string& r2 = s1 + s1; // okay: lvalue reference to const extends lifetime
// //  r2 += "Test";                    // error: can't modify through reference to const

//     std::string&& r3 = s1 + s1;      // okay: rvalue reference extends lifetime
//     r3 += "Test";                    // okay: can modify through reference to non-const
//     std::cout << r3 << '\n';
// }

struct S
{
    char a; // size: 1, alignment: 1
    int16_t b; // size: 1, alignment: 1
}; // size: 2, alignment: 1
 
// objects of type X must be allocated at 4-byte boundaries
// because X.n must be allocated at 4-byte boundaries
// because int's alignment requirement is (usually) 4
struct X
{
    X() = delete;
    X(int x) {n=x;}

    char c; // size: 1, alignment: 1
    int n;  // size: 4, alignment: 4
    int n2;
    int64_t t;
    // three bytes of padding bits
}; //__attribute__((packed)); // size: 8, alignment: 4  
 
constexpr int product(int x, int y) { return (x * y); }

  
int main()
{
    constexpr int ca = 10*std::abs(-5);

    X xx(10);
    std::cout << "alignof(S) = " << alignof(S) << '\n'
              << "sizeof(S)  = " << sizeof(S) << '\n'
              << "alignof(X) = " << alignof(X) << '\n'
              << "sizeof(X)  = " << sizeof(X) << "," << sizeof(xx) << '\n';
    std::cout << offsetof(X, c) << std::endl;
    std::cout << offsetof(X, n) << std::endl;
    std::cout << offsetof(X, n2) << std::endl;
    std::cout << offsetof(X, t) << std::endl;

    std::string s5{'a', 'b'};

    std::pair pa{'a', 2};
    std::cout << pa.second << std::endl; 

    int a[2] = {1, 2};
 
    auto [x, y] = a;    // creates e[2], copies a into e,
                        // then x refers to e[0], y refers to e[1]
    auto& [xr, yr] = a; // xr refers to a[0], yr refers to a[1]
    xr = 4;
    std::cout << a[0] << std::endl;

    constexpr int cx = product(10, 20);
    int x1,x2;
    std::cin >> x1 >> x2;
    x = product(x1,x2);
    std::cout << x << std::endl;
}