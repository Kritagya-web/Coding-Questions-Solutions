// Implemented by Kritagya Kumra
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    for (int i = 0; i <= (n - 2); i++)
        for (int j = i + 1; j <= (n - 1); j++)
            swap(arr[i][j], arr[j][i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // for (int i = 0; i < n; i++)
    //     reverse(arr[i].begin(), arr[i].end());
}
// Implemented by Kritagya Kumra