#include <iostream>

void fillArray(int (&arr)[10])
{
    for (int& x : arr)
    {
        std::cin >> x;
    }
}

int main()
{
    int arr[10]{};

    fillArray(arr);

    return 0;
}