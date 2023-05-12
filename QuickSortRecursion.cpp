// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
int getPartition(int *arr, int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void QuickSort(int *arr, int start, int end)
{
    // Base case
    if (start >= end)
    {
        return;
    }
    // Get the partition
    int Partition = getPartition(arr, start, end);
    // Sort the left half
    QuickSort(arr, start, Partition - 1);
    // Sort the right half
    QuickSort(arr, Partition + 1, end);
    // Merge two sorted arrays
}
int main()
{
    int arr[10] = {23, 1, 13, 53, 45, 21, 5, 3, 55, 8};
    int size = 10;
    QuickSort(arr, 0, size - 1);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}
// Implemented by Kritagya Kumra