// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;

int find_duplicate(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = result ^ arr[i];
    }
    for (int j = 1; j < n; j++)
    {
        result = result ^ j;
    }
    return result;
}
int main()
{
    int array[5] = {2, 1, 3, 3, 4};
    cout << find_duplicate(array, 5);
}
// Implemented by Kritagya Kumra