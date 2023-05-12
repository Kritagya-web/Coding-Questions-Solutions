// Implemented by Kritagya Kumra
#include <iostream>
#include <stdlib.h>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0, count = 0;
    int total_ele = m + n;
    while (i < n && j < m)
    {

        if (arr1[i] < arr2[j] && i != n)
        {
            arr3[count++] = arr1[i++];
        }
        else if (arr2[j] < arr1[i] && j != m)
        {
            arr3[count++] = arr2[j++];
        }
    }
    if (n > m)
    {
        // while (i<n)
        while (count != total_ele)
        {
            arr3[count++] = arr1[i++];
        }
    }
    else
    {
        // while (j<m)
        while (count != total_ele)
        {
            arr3[count++] = arr2[j++];
        }
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[3] = {2, 4, 6};
    int arr3[8] = {0};

    merge(arr1, 5, arr2, 3, arr3);
    cout << endl;
    print(arr3, 8);
    return 0;
}
// Implemented by Kritagya Kumra