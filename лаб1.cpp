#include <iostream>

void fillArray(int (&arr)[10])
{
    for (int& x : arr)
    {
        std::cin >> x;
    }
}

void printArray(const int (&arr)[10])
{
    for (auto x : arr)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;
}
void swapElements(int (&arr)[10], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
int main()
{
    int arr[10]{};

    fillArray(arr);
    printArray(arr);
    swapElements(arr, 0, 9);
    printArray(arr);
    return 0;
}