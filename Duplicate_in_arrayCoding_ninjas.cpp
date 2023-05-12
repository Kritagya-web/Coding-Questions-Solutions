// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;

int find_duplicate(int arr[], int n)
{
    int result = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (result ^ arr[i + 1] == 0)
        {
            return arr[i + 1];
        }
        else
        {
            result = result ^ arr[i + 1];
        }
    }
    return result;
}
int main()
{
    int array[5] = {21, 12, 3, 13, 12};
    cout << find_duplicate(array, 5);
}
// Implemented by Kritagya Kumra
