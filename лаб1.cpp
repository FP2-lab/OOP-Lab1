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

int main()
{
    int arr[10]{};

    fillArray(arr);
    printArray(arr);

    return 0;
}