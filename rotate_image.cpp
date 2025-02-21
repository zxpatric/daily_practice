#include <iostream>
#include "image.hh"

template <typename T, int row, int col>
void Image<T, row, col>::rotate_in_place()
{
    for (int i = 0; i < row / 2; ++i)
    {
        for (int j = i; j < col - i - 1; ++ j)
        {
            // swap all 4 corners 
            T temp = data_storage_[i][j];
            data_storage_[i][j] = data_storage_[row - j - 1][i];
            data_storage_[row - j - 1][i] = data_storage_[row - i - 1][col - j - 1];
            data_storage_[row - i - 1][col - j - 1] = data_storage_[j][col - i - 1];
            data_storage_[j][col - i - 1] = temp;
        }
    }
}


int main()
{
    Image<int, 4, 4> a_image;
    a_image.print();
    a_image.rotate_in_place();
    a_image.print();
}