#include <iostream>
using namespace std;
void print(int *arr, int size)
{
    cout << "For Size " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void InsertionSort(int *arr, int size, int index)
{
    // base case
    if (index == size)
        return;

    int curr = arr[index];
    int j = index - 1;

    while (j >= 0)
    {
        if (curr < arr[j])
        { // found greater value than curr shift to right
            arr[j + 1] = arr[j--];
        }
        else // Smaller element found
            break;
    }
    arr[j + 1] = curr; // place curr element at correct place

    // one part Done recursion will do other work;
    InsertionSort(arr, size, index + 1);
}
int main()
{
    int arr[5] = {12, 3, 22, 1, 2};
    InsertionSort(arr, 5, 1);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}
