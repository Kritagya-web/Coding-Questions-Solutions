// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
bool LinearSearch(int arr[], int size, int element)
{
    if (size == 0)
    {
        return false;
    }
    if (arr[0] == element)
    {
        return true;
    }
    bool ans = LinearSearch(arr + 1, size - 1, element);
    return ans;
}
int main()
{
    int arr[10] = {1, 3, 5, 6, 13, 22, 111, 112, 113, 224};
    int element = 13;
    cout << "Element " << element << " is ";
    if (LinearSearch(arr, 10, 13))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }
}
// Implemented by Kritagya Kumra