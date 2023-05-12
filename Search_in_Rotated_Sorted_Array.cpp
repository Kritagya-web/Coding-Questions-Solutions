// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
int Pivot_Search(int *A, int n)
{
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (A[mid] >= A[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }

        mid = start + (end - start) / 2;
    }
    return start;
}

int binarySearch(int *input, int s, int e, int key)
{
    int start = s, end = e;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (input[mid] == key)
        {
            return mid;
        }
        else if (input[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int arr[9] = {7, 8, 9, 11, 0, 1, 2, 4, 5};
    int k = 0;
    int answer = 0;
    int n = 9;
    int pivot = Pivot_Search(arr, n);
    if (arr[pivot] <= k && k <= arr[n - 1])
    {
        cout << binarySearch(arr, pivot, n - 1, k);
    }
    else
    {
        cout << binarySearch(arr, 0, pivot - 1, k);
    }
}
// Implemented by Kritagya Kumra