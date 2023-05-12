// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
long Merge(long *arr, long start, long end)
{
    long ans = 0;
    long mid = start + (end - start) / 2;
    long length1 = mid - start + 1;
    long length2 = end - mid;
    long *arr1 = new long[length1];
    long *arr2 = new long[length2];
    // Copy values of the arrays longo 2 different arrays and then
    // we would combine those
    long mainIndex = start;
    for (long i = 0; i < length1; i++)
    {
        arr1[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for (long i = 0; i < length2; i++)
    {
        arr2[i] = arr[mainIndex++];
    }

    // Printing the arrays
    cout << endl;
    cout << "Printing the arrays1" << endl;
    for (long i = 0; i < length1; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << endl;
    cout << "Printing the arrays2" << endl;
    for (long i = 0; i < length2; i++)
    {
        cout << arr2[i] << " ";
    }

    // Merge two sorted arrays using the index

    long ArrayIndex1 = 0;
    long ArrayIndex2 = 0;
    mainIndex = start;
    while (ArrayIndex1 < length1 && ArrayIndex2 < length2)
    {
        // Choose the smaller of the two values and then add it to the main array
        if (arr1[ArrayIndex1] > arr2[ArrayIndex2])
        {
            ans += 1;
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
long InversionCount(long *arr, long start, long end)
{
    // Base case
    if (start >= end)
    {
        return 0;
    }
    long mid = start + (end - start) / 2;
    long ans = 0;
    // Sort the left half
    InversionCount(arr, start, mid);
    // Sort the right half
    InversionCount(arr, mid + 1, end);
    // Merge two sorted arrays
    ans += Merge(arr, start, end);
    return ans;
}
int main()
{
    long arr[10] = {23, 1, 13, 53, 45, 21, 5, 3, 55, 8};
    long size = 10;
    cout << InversionCount(arr, 0, size) << endl;
    for (long i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}
// Implemented by Kritagya Kumra