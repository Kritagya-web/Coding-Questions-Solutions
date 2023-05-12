// Implemented by Kritagya Kumra
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> nums, vector<vector<int>> answer, int index)
{
    cout << "For index " << index << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[0][i] << " ";
    }
    cout << endl;
}
bool isSafe(vector<vector<int>> &m, vector<vector<int>> visited, int n, int x, int y)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (m[x][y] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solveForMaze(vector<vector<int>> &m, vector<vector<int>> visited, int n, vector<string> &answer,
                  int xIndex, int yIndex, string path)
{
    if (xIndex == n - 1 && yIndex == n - 1)
    {
        answer.push_back(path);
        return;
    }
    visited[xIndex][yIndex] = 1;

    // Check for the down
    int newX = xIndex + 1;
    int newY = yIndex;

    if (isSafe(m, visited, n, newX, newY))
    {
        path.push_back('D');
        solveForMaze(m, visited, n, answer, newX, newY, path);
        path.pop_back();
    }

    // Check for the left
    newX = xIndex;
    newY = yIndex - 1;

    if (isSafe(m, visited, n, newX, newY))
    {
        path.push_back('L');
        solveForMaze(m, visited, n, answer, newX, newY, path);
        path.pop_back();
    }

    // Check for the right
    newX = xIndex;
    newY = yIndex + 1;

    if (isSafe(m, visited, n, newX, newY))
    {
        path.push_back('R');
        solveForMaze(m, visited, n, answer, newX, newY, path);
        path.pop_back();
    }

    // Check for the top
    newX = xIndex - 1;
    newY = yIndex;

    if (isSafe(m, visited, n, newX, newY))
    {
        path.push_back('U');
        solveForMaze(m, visited, n, answer, newX, newY, path);
        path.pop_back();
    }
    visited[xIndex][yIndex] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    int xIndex = 0;
    int yIndex = 0;

    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    string path = "";

    vector<string> answer;
    if (m[0][0] == 0)
    {
        return answer;
    }
    solveForMaze(m, visited, n, answer, xIndex, yIndex, path);
    // sort(answer.begin(), answer.end());
    return answer;
}
int main()
{
    vector<string> Finalanswer;
    int m[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = 4;
    Finalanswer = findPath(&m[][4], n);

    cout << endl;
    cout << "Final Answer :-";
    cout << endl;
    for (int i = 0; i < Finalanswer.size(); i++)
    {
        cout << Finalanswer[i] << " ";
    }
    cout << endl;
}
// Implemented by Kritagya Kumra