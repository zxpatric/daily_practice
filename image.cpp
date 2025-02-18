#include <iostream>

using namespace std;

// Class image within the stack. Use new if it is big and shall be in heap.
template <typename T, int row, int col>
struct Image
{
    T m_data[row][col];

    Image()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                m_data[i][j] = i * col + j;
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
                result.m_data[i][j] = m_data[i][j];
                if (i > 0)
                {
                    result.m_data[i][j] += result.m_data[i - 1][j];
                }
                if (j > 0)
                {
                    result.m_data[i][j] += result.m_data[i][j - 1];
                }
                if (i > 0 && j > 0)
                {
                    result.m_data[i][j] -= result.m_data[i - 1][j - 1];
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
                result.m_data[i][j] = m_data[i][j];
                if (i > 0)
                {
                    result.m_data[i][j] += m_data[i - 1][j];
                    ++count;
                }
                if (i < row-1)
                {
                    result.m_data[i][j] += m_data[i + 1][j];
                    ++count;
                }
                if (j > 0)
                {
                    result.m_data[i][j] += m_data[i][j - 1];
                    ++count;
                }
                if(j < col-1)
                {
                    result.m_data[i][j] += m_data[i][j + 1];
                    ++count;
                }
                if (i > 0 && j > 0)
                {
                    result.m_data[i][j] += m_data[i - 1][j - 1];
                    ++count;
                }
                if (i > 0 && j < col-1)
                {
                    result.m_data[i][j] += m_data[i - 1][j + 1];
                    ++count;
                }
                if (i < row-1 && j > 0)
                {
                    result.m_data[i][j] += m_data[i + 1][j - 1];
                    ++count;
                }
                if (i < row-1 && j < col-1)
                {
                    result.m_data[i][j] += m_data[i + 1][j + 1];
                    ++count;
                }
                result.m_data[i][j] /= (T)count;
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
                cout << m_data[i][j] << ",";
            }
            cout << endl;
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