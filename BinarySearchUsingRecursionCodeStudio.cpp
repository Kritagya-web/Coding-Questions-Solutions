// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;

// Way 2
int Binary_Search(int A[], int start, int end, int key)
{
    int mid = (start + end) / 2;
    if (start > end)
    {
        return -1;
    }
    if (A[mid] == key)
    {
        return mid;
    }
    else
    {
        if (A[mid] < key)
        {
            return Binary_Search(A, mid + 1, end, key);
        }
        else
        {
            return Binary_Search(A, start, mid - 1, key);
        }
    }
}
int main()
{
    int array[6] = {3, 5, 7, 8, 10, 20};
    int n = sizeof(array) / sizeof(array[0]);
    int result = Binary_Search(array, 0, n - 1, 10);
    if (result)
    {
        cout << "Element found at " << result;
    }
    else
    {
        cout << "Element not found";
    }
    return 0;
}
// Implemented by Kritagya Kumra