// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}
void sort012(int A[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        while (A[i] == 0 && i < j)
        {
            i++;
        }
        while (A[j] == 2 && i < j)
        {
            j++;
        }

        if (i < j)
        {
            swap(A[i], A[j]);
            j--;
            i++;
        }
    }
}
int main()
{
    int array[6] = {0, 1, 2, 2, 1, 0};
    int n = sizeof(array) / sizeof(array[0]);
    sort012(array, n);
    printArray(array, n);
    return 0;
}
// Implemented by Kritagya Kumra