#include <iostream>

// Class image within the stack. Use new if it is big and shall be in heap.
template <typename T, int row, int col>
struct Image
{
    T data_storage_[row][col];

    Image()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                data_storage_[i][j] = i * col + j;
            }
        }
    }

    Image integral() const
    {
        Image<T, row, col> result;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                result.data_storage_[i][j] = data_storage_[i][j];
                if (i > 0)
                {
                    result.data_storage_[i][j] += result.data_storage_[i - 1][j];
                }
                if (j > 0)
                {
                    result.data_storage_[i][j] += result.data_storage_[i][j - 1];
                }
                if (i > 0 && j > 0)
                {
                    result.data_storage_[i][j] -= result.data_storage_[i - 1][j - 1];
                }
            }
        }
        return result;
    }

    Image mean_filter() const
    {
        Image<T, row, col> result;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int count = 1;
                result.data_storage_[i][j] = data_storage_[i][j];
                if (i > 0)
                {
                    result.data_storage_[i][j] += data_storage_[i - 1][j];
                    ++count;
                }
                if (i < row-1)
                {
                    result.data_storage_[i][j] += data_storage_[i + 1][j];
                    ++count;
                }
                if (j > 0)
                {
                    result.data_storage_[i][j] += data_storage_[i][j - 1];
                    ++count;
                }
                if(j < col-1)
                {
                    result.data_storage_[i][j] += data_storage_[i][j + 1];
                    ++count;
                }
                if (i > 0 && j > 0)
                {
                    result.data_storage_[i][j] += data_storage_[i - 1][j - 1];
                    ++count;
                }
                if (i > 0 && j < col-1)
                {
                    result.data_storage_[i][j] += data_storage_[i - 1][j + 1];
                    ++count;
                }
                if (i < row-1 && j > 0)
                {
                    result.data_storage_[i][j] += data_storage_[i + 1][j - 1];
                    ++count;
                }
                if (i < row-1 && j < col-1)
                {
                    result.data_storage_[i][j] += data_storage_[i + 1][j + 1];
                    ++count;
                }
                result.data_storage_[i][j] /= (T)count;
            }

        }
        return result;
    }


    void print()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                std::cout << data_storage_[i][j] << ",";
            }
            std::cout << std::endl;
        }
    }
};

int main ()
{
    Image<float, 3, 3> img;
    img.print();
    Image<float, 3, 3> result_integral = img.integral();
    result_integral.print();
    Image<float, 3, 3> result_mean = img.mean_filter();
    result_mean.print();
    return 0;
}