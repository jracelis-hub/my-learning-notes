#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int *array, int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0 + i; j < s - 1; j++)
        {
            if (array[j] >= array[j + 1])
            {
                swap(array[j], array[j+1]);
            }
        }
    }
}

void bubble_sort_example(int *array, int s)
{
    bool issort = false;
    while (!issort)
    {
        issort = true;
        for (int i = 0; i < s - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                issort = false;
            }
        }
    }
}

int main()
{
    int array[] = {3, 1, 10, 33, 5, 14};

    auto s = sizeof(array) / sizeof(int);

    bubble_sort_example(array, s);

    for (int number : array)
    {
        std::cout << number << std::endl;
    }

    return 0;
}