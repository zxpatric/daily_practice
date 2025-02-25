#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
    std::vector<int> array = {1,2,3,4,5,6,7};

    std::vector<int> results(array.size());

    int rotate_step = 9;

    rotate_step %= array.size();

    std::copy(array.end()-rotate_step, array.end(), results.begin());
    std::copy(array.begin(), array.end(), results.begin()+rotate_step);

    for (auto val_ : results)
    {
        std::cout << val_ << std::endl;       
    }

    return 0;
}