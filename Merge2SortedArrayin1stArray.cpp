// Implemented by Kritagya Kumra
#include <iostream>
#include <stdlib.h>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m)
{
    int i = 0, j = 0, count = 0;
    int total_ele = m + n;
    while (i < n && j < m)
    {

        if (arr1[i] < arr2[j] && i != n)
        {
            // arr3[count++] = arr1[i++];
            i++;
        }
        else if (arr2[j] < arr1[i] && j != m)
        {
            // arr3[count++] = arr2[j++];
            for (int p = n + count; p - count >= i; p--)
            {
                arr1[p] = arr1[p - 1];
            }
            arr1[i] = arr2[j++];
            count++;
            i = i + 1;
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
    int arr1[10] = {1, 3, 5, 7, 9};
    int arr2[3] = {2, 4, 6};

    merge(arr1, 5, arr2, 3);
    cout << endl;
    print(arr1, 8);
    return 0;
}
// Implemented by Kritagya Kumra