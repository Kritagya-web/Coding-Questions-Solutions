// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
void print(int *arr, int size)
{
    cout << "For Size " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int *arr, int size)
{
    // print(arr, size);
    if (size == 0)
    {
        return;
    }
    int minIndex = 0;
    for (int j = 1; j < size; j++)
    {
        if (arr[minIndex] > arr[j])
        {
            minIndex = j;
        }
    }
    swap(arr[0], arr[minIndex]);
    selectionSort(arr + 1, size - 1);
}
int main()
{
    int arr[5] = {12, 3, 22, 1, 2};
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}

// Implemented by Kritagya Kumra