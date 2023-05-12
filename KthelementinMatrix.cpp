// Implemented by Kritagya Kumra
//{ Driver Code Starts
//  kth largest element in a 2d array sorted row-wise and column-wise
//  #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000
// int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int n;
    //     cin >> n;

    //     for (int i = 0; i < n; i++)
    //         for (int j = 0; j < n; j++)
    //             cin >> mat[i][j];
    //     int r;
    //     cin >> r;
    //     cout << kthSmallest(mat, n, r) << endl;
    // }
    int mat[MAX][MAX] = {{16, 28, 60, 64}, {22, 41, 63, 91}, {27, 50, 87, 93}, {36, 78, 87, 94}};
    cout << kthSmallest(mat, 4, 3) << endl;
    // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}

// } Driver Code Ends

int kthSmallest(int Mat[MAX][MAX], int N, int k)
{
    vector<int> temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp.push_back(Mat[i][j]);
        }
    }
    sort(temp.begin(), temp.end());
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Mat[i][j] = temp[counter];
            counter++;
        }
    }
    return Mat[0][k - 1];
}

// Implemented by Kritagya Kumra