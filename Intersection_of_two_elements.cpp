#include <iostream>
using namespace std;
/*
void find_intersection(int arr[], int n, int arr2[], int n1)
{
    int result = 0;
    for (int j = 0; j < n1; j++)
    {
        if (result ^ arr[j] ^ arr2[j] != 0)
        {
            cout << arr2[j] << " ";
        }
        else
        {
            result = result ^ arr[j] ^ arr2[j];
        }
    }
}

int main()
{
    int array[5] = {2, 1, 3, 4, 8};
    int array2[5] = {1, 2, 3, 9, 6};
    find_intersection(array, 5, array2, 5);
}
*/

void find_intersection(int arr[], int n, int arr2[], int n1)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = arr[i];
        for (int i = 0; i < n1; i++)
        {
            if (result == arr2[i])
            {
                cout << arr2[i] << " ";
            }
        }
    }
}
int main()
{
    int array[5] = {2, 1, 3, 8, 6};
    int array2[5] = {61, 2, 3, 7, 9};
    find_intersection(array, 5, array2, 5);
}
