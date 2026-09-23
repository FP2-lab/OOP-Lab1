#include <iostream>

struct SafeArray
{
    int* data;
    int size;
};
SafeArray createArray(int size)
{
    SafeArray arr;
    arr.data = new int[size]{};
    arr.size = size;

    return arr;
}
int& getElement(SafeArray& arr, int index)
{
    static int errorValue = 0;

    if (index < 0 || index >= arr.size)
    {
        std::cout << "Ошибка: индекс вне границ массива" << std::endl;
        return errorValue;
    }

    return arr.data[index];
}
void printSafe(const SafeArray& arr)
{
    for (int i = 0; i < arr.size; ++i)
    {
        std::cout << arr.data[i] << " ";
    }

    std::cout << std::endl;
}
void reSizeArray(SafeArray& arr, int N, int M)
{
    int* newData = new int[M]{};

    int copySize = N < M ? N : M;

    for (int i = 0; i < copySize; ++i)
    {
        newData[i] = arr.data[i];
    }

    if (M < N)
    {
        std::cout << "Удаленные элементы: ";

        for (int i = M; i < N; ++i)
        {
            std::cout << arr.data[i] << " ";
        }

        std::cout << std::endl;
    }

    delete[] arr.data;

    arr.data = newData;
    arr.size = M;
}
int main()
{
    SafeArray myArr = createArray(5);

    getElement(myArr, 0) = 10;
    getElement(myArr, 1) = 20;
    getElement(myArr, 2) = 999;
    getElement(myArr, 3) = 40;
    getElement(myArr, 4) = 50;

    std::cout << "Исходный массив: ";
    printSafe(myArr);

    reSizeArray(myArr, 5, 7);

    std::cout << "После увеличения: ";
    printSafe(myArr);

    reSizeArray(myArr, 7, 4);

    std::cout << "После уменьшения: ";
    printSafe(myArr);

    getElement(myArr, 10) = 500;
    delete[] myArr.data;
    return 0;
}