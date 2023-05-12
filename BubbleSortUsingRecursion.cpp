// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
void bubbleSort(int *arr, int n)
{
    // Base case :- The element is already sorted
    if (n == 0 || n == 1)
    {
        return;
    }
    // Try to sort by trying to sort an element in a single pass and then we
    // would remove an element from n as at the end of one pass one element would
    // get to its sorted position

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubbleSort(arr, n - 1);
}
int main()
{
    int arr[5] = {12, 3, 22, 1, 2};
    bubbleSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}
// Implemented by Kritagya Kumra