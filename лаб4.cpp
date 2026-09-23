#include <iostream>
#include <string>

int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }

    return matrix;
}

int main()
{
    return 0;
}