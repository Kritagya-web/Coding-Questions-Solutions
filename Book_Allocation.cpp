// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;

bool ispossible(int arr[], int barrier, int n, int students)
{
    int allocated_student = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > barrier)
        {
            return false;
        }
        if (pages + arr[i] > barrier)
        {
            allocated_student += 1;
            pages += arr[i];
        }
        else
        {
            pages += arr[i];
        }
    }
    if (allocated_student > students)
    {
        cout << pages;
        return true;
    }
    else
    {
        cout << pages;
        return false;
    }
}
int sum(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += i;
    }
    return ans;
}

int main()
{
    int arr[4] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = arr[0], end = sum(arr, n);
    cout << start << " " << end;
    int mid = start + (end - start) / 2;
    int res = -1;

    while (start <= end)
    {
        if (ispossible(arr, mid, n, 2))
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << start;
    return 0;
}
// Implemented by Kritagya Kumra