// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }

    bool ans = isSorted(arr + 1, size - 1);
    return ans;
}
int main()
{
    int arr[10] = {1, 3, 5, 6, 13, 22, 111, 112, 113, 224};
    cout << "Is the array sorted" << endl;
    if (isSorted(arr, 10))
    {
        cout << "Yes, the given array is sorted";
    }
    else
    {
        cout << "No, the given array is not sorted";
    }
}
// Implemented by Kritagya Kumra