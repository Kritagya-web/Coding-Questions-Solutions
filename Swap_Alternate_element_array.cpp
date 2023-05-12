// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;

void swap_alternate(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int array[5] = {1, 23, 31, 54, 3};
    int evenarray[6] = {1, 23, 3, 91, 54, 3};
    swap_alternate(array, 5);
    printArray(array, 5);
    cout << endl;
    swap_alternate(evenarray, 6);
    printArray(evenarray, 6);
}
// Implemented by Kritagya Kumra