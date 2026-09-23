#include <iostream>

void process(int*& arr, int size)
{
    int index = -1;

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 0)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        int* newArr = new int[index];

        for (int i = 0; i < index; ++i)
        {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }
}

int main()
{
    int N;
    std::cin >> N;

    int* arr = new int[N]{};

    for (int i = 0; i < N; ++i)
    {
        std::cin >> arr[i];
    }

    int newSize = N;

    for (int i = 0; i < N; ++i)
    {
        if (arr[i] < 0)
        {
            newSize = i;
            break;
        }
    }

    process(arr, N);

    for (int i = 0; i < newSize; ++i)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}