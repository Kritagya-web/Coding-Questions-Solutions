// Implemented by Kritagya Kumra
#include <iostream>
#include <string>
using namespace std;

void LargestRowSum(int arr[][4], int row, int col)
{
    // Row wise sum Printing
    int max = 0, index = 0;
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 4; col++)
        {
            sum = sum + arr[row][col];
        }
        cout << "Sum of the elements in row :- " << row << " is " << sum;
        if (sum > max)
        {
            max = sum;
            index = row;
        }
        cout << endl;
    }

    cout << "Maximum Sum of the elements is " << max << " present in the row " << index;
}

void RowWiseSum(int arr[][4], int row, int col)
{
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 4; col++)
        {
            sum = sum + arr[row][col];
        }
        cout << "Sum of the elements in row :- " << row << " is " << sum;
        cout << endl;
    }
}

void ColWiseSum(int arr[][4], int row, int col)
{
    for (int row = 0; row < 4; row++)
    {
        int sum = 0;
        for (int col = 0; col < 3; col++)
        {
            sum = sum + arr[col][row];
        }
        cout << "Sum of the elements in row :- " << row << " is " << sum;
        cout << endl;
    }
}
int main()
{
    int arr[3][4];

    // Input the elements
    cout << "Enter elements of the array are " << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }
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

    // Row wise sum Printing

    // RowWiseSum(arr, 3, 4);

    // Column wise sum Printing

    // ColWiseSum(arr[][4], 3, 4)

    // Largest Row Sum Printing
    LargestRowSum(arr, 3, 4);
    return 0;
}
// Implemented by Kritagya Kumra