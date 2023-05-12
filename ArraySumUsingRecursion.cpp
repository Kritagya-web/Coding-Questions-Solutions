// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
int arraySum(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }
    int sum = arraySum(arr + 1, size - 1);
    sum = sum + arr[0];
    return sum;
}
int main()
{
    int arr[10] = {1, 3, 5, 6, 13, 22, 111, 112, 113, 224};
    cout << "Sum of the array elements is" << endl;
    cout << arraySum(arr, 10);
}
// Implemented by Kritagya Kumra