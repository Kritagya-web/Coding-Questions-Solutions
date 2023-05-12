// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
void printarray(int arr[])
{
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
}
void reverseArray(int arr[], int m)
{
    int count = 0;
    for (int i = m + 1; i < 7; i++)
    {
        swap(arr[i], arr[9 - count - 1]);
        count++;
    }
}

int main()
{
    int array[9] = {10, 4, 5, 2, 3, 6, 1, 3, 6};
    reverseArray(array, 3);
    printarray(array);
}
// Implemented by Kritagya Kumra