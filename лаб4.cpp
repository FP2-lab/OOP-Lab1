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
void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}
int main()
{
    int rows = 3;
    int cols = 3;

    int** matrix = allocateMatrix(rows, cols);

    fillMatrix(matrix, rows, cols);

    // 1. Без дополнительных параметров
    printMatrix(matrix, rows, cols);

    // 2. Только с заголовком
    printMatrix(matrix, rows, cols, true, "Оценки студентов");

    // 3. Со всеми параметрами
    printMatrix(matrix, rows, cols, false, "Матрица без рамки");
    freeMatrix(matrix, rows);
    return 0;
}