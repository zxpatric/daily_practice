#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve_layer(int& num, int n, int k, vector<int>& used)
{
    for(int i=0; i<n; ++i)
    {
        if (std::find(used.begin(), used.end(), i) == used.end())
        {
            if(k==n-1)
            {
                ++num;
            }
            else
            {
                used.push_back(i);
                solve_layer(num, n, k+1, used);
                used.pop_back();
            }
        }
    }
}

int main() {

	// Replace this placeholder return statement with your code
    int n = 3;
	int num = 0;
    int k = 0;
    vector<int> used;
	
	solve_layer (num, n, k, used);
    return num;
} 