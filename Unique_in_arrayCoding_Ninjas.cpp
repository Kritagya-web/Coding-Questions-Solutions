// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;

int find_unique(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = result ^ arr[i];
    }
    return result;
}
int main()
{
    int array[5] = {21, 12, 13, 13, 12};
    cout << find_unique(array, 5);
}
// Implemented by Kritagya Kumra