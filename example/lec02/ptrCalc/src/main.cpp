#include <iostream>

using namespace std;

void printArray(const int *arr, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << endl;
}

template<size_t N>
void printArray(const int (&arr)[N])
{
    for (int i = 0; i < N; i++)
    {
        cout << arr[i];
        if (i < N - 1)
            cout << ", ";
    }
    cout << endl;
}

int main()
{
    int a[] = {1, 2, 3};
    int *arr = a;
    int *p = &a[0];

    cout << p << " " << arr << " " << *arr << endl;
    arr += 1;
    cout << *arr << endl;

    cout << *p << " " << *p++ << endl;
    cout << *++p << endl;

    printArray(a, sizeof(a) / sizeof(int));

    int a2[] = {1, 2, 3, 4};
    printArray(a2);

    return 0;
}
