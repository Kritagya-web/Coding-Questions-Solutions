// Implemented by Kritagya Kumra
#include <iostream>
#include <algorithm>
using namespace std;

void pair_sum(int arr[], int n)
{
    int start = 0, end1 = 4;
    while (start <= end1)
    {
        if (arr[start] + arr[end1] == n)
        {
            cout << arr[start] << " " << arr[end1];
            start++;
            end1--;
        }
        else if (arr[start] + arr[end1] > n)
        {
            end1--;
        }
        else
        {
            if (arr[start + 1] + arr[end1] == n)
            {
                cout << " " << arr[start + 1] << " " << arr[end1];
            }
            else
            {
                end1++;
            }
        }
    }
}
int main()
{
    int array[5] = {2, 18, 8, 1, 12};
    pair_sum(array, 20);
}
// Implemented by Kritagya Kumra