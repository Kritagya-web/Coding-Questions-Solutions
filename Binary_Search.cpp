// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;

int Binary_Search(int A[], int n, int key)
{
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (A[mid] == key)
        {
            return mid;
        }
        else if (A[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}
int main()
{
    int array[6] = {3, 5, 7, 8, 10, 20};
    int n = sizeof(array) / sizeof(array[0]);
    int result = Binary_Search(array, n, 20);
    cout << result;
    return 0;
}
// Implemented by Kritagya Kumra