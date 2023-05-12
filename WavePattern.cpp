// Implemented by Kritagya Kumra
#include <iostream>
#include <string>
using namespace std;

void evenTurn(int arr[][4], int index, int rowCount)
{
    int j = 0;
    while (j < rowCount)
    {
        cout << arr[j][index] << " ";
        j++;
    }
}
void oddTurn(int arr[][4], int index, int rowCount)
{
    int j = rowCount - 1;
    while (j >= 0)
    {
        cout << arr[j][index] << " ";
        j--;
    }
}
int main()
{
    int arr[3][4] = {3, 4, 5, 6, 7, 9, 1, 2, 3, 11, 8, 6};

    // Input the elements

    // cout << "Enter elements of the array are " << endl;
    // for (int row = 0; row < 3; row++)
    // {
    //     for (int col = 0; col < 4; col++)
    //     {
    //         cin >> arr[row][col];
    //     }
    // }

    // Printing the elements

    cout << "The elements of the array are " << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int i = 0, j = 0;
    int n = 4;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            evenTurn(arr, i, 3);
        }
        else
        {
            oddTurn(arr, i, 3);
        }
        i++;
        n--;
    }

    // Row wise sum Printing

    // RowWiseSum(arr, 3, 4);

    // Column wise sum Printing

    // ColWiseSum(arr[][4], 3, 4)

    // Largest Row Sum Printing
    return 0;
}
// Implemented by Kritagya Kumra