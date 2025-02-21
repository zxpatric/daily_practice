#pragma

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

    Image integral() const;

    Image mean_filter() const;

    void rotate_in_place();

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