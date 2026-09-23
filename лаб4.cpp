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
void fillMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "Введите элемент [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}
void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, std::string title = "Matrix")
{
    std::cout << title << std::endl;

    if (showBorders)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "----";
        }

        std::cout << "-" << std::endl;
    }

    for (int i = 0; i < rows; ++i)
    {
        if (showBorders)
        {
            std::cout << "| ";
        }

        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }

        if (showBorders)
        {
            std::cout << "|" << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
    }

    if (showBorders)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "----";
        }

        std::cout << "-" << std::endl;
    }
}
int main()
{
    return 0;   
}