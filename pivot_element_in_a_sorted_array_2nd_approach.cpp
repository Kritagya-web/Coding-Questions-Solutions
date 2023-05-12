// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;

int Pivot_Search(int A[], int n)
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
int main()
{
    // int array[9] = {3, 4, 7, 8, 10, 20, 2, 3, 5};
    int array[8] = {4, 5, 6, 7, 8, 1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);
    int result = Pivot_Search(array, n);
    cout << result;
    return 0;
}
// Implemented by Kritagya Kumra