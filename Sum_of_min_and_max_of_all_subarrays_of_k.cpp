// Implemented by Kritagya Kumra
#include <iostream>
#include <queue>
using namespace std;

int solve(int *arr, int n, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    // Tackle the first list of k numbers
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    // For next window
    //  For the remaining window
    for (int i = k; i < n; i++)
    {
        // Removal logic for maxi array to remove one element from front
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_back();
        }
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_back();
        }
        // Addition of other one element into the window of size k
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}
int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;

    return 0;
}
// Implemented by Kritagya Kumra