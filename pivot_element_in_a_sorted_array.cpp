// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;

int Pivot_Search(int A[], int n)
{
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    // cout << mid << endl;
    while (start < end)
    {
        if (A[mid] > A[end])
        {
            start = mid + 1;
        }
        else if (A[mid] < A[mid - 1] && A[mid] < A[mid + 1])
        {
            return mid;
        }
        else if (A[mid] < A[end])
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
        // cout << mid << endl;
    }
    return -1;
}
int main()
{
    // int array[9] = {3, 5, 7, 8, 10, 20, 2, 13, 15};
    // int array[9] = {3, 4, 7, 8, 10, 20, 2, 3, 5};
    int array[8] = {4, 5, 6, 7, 8, 1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);
    int result = Pivot_Search(array, n);
    cout << result;
    return 0;
}
// Implemented by Kritagya Kumra