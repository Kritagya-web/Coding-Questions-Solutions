// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
int Merge(int *arr, int start, int end)
{
    int ans = 0;
    int mid = start + (end - start) / 2;
    int length1 = mid - start + 1;
    int length2 = end - mid;
    int *arr1 = new int[length1];
    int *arr2 = new int[length2];
    // Copy values of the arrays into 2 different arrays and then
    // we would combine those
    int mainIndex = start;
    for (int i = 0; i < length1; i++)
    {
        arr1[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for (int i = 0; i < length2; i++)
    {
        arr2[i] = arr[mainIndex++];
    }
    // Merge two sorted arrays using the index

    int ArrayIndex1 = 0;
    int ArrayIndex2 = 0;
    mainIndex = start;
    while (ArrayIndex1 < length1 && ArrayIndex2 < length2)
    {
        // Choose the smaller of the two values and then add it to the main array
        if (arr1[ArrayIndex1] < arr2[ArrayIndex2])
        {
            ans += (length1 - ArrayIndex1);
            arr[mainIndex++] = arr1[ArrayIndex1++];
        }
        else
        {
            arr[mainIndex++] = arr2[ArrayIndex2++];
        }
    }
    // Check for the elements left if one array is greater than the other elements
    while (ArrayIndex1 < length1)
    {
        // if left array has more elements
        arr[mainIndex++] = arr1[ArrayIndex1++];
    }
    while (ArrayIndex2 < length2)
    {
        //  if right array has more elements
        arr[mainIndex++] = arr2[ArrayIndex2++];
    }
    delete[] arr1;
    delete[] arr2;
    return ans;
}
int MergeSort(int *arr, int start, int end)
{
    // Base case
    if (start >= end)
    {
        return 0;
    }
    int mid = start + (end - start) / 2;
    int ans = 0;
    // Sort the left half
    MergeSort(arr, start, mid);
    // Sort the right half
    MergeSort(arr, mid + 1, end);
    // Merge two sorted arrays
    ans += Merge(arr, start, end);
    return ans;
}
int main()
{
    int arr[10] = {23, 1, 13, 53, 45, 21, 5, 3, 55, 8};
    int size = 10;
    cout << MergeSort(arr, 0, size) << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}
// Implemented by Kritagya Kumra