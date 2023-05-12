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
void solvePermutation(vector<int> nums, vector<vector<int>> &answer, int index)
{
    print(nums, answer, index);
    // Base case :- when index crosses the num's last element
    if (index >= nums.size())
    {
        answer.push_back(nums);
        return;
    }
    // Start iterating the nums from index to nums.size()-1 and
    // start swapping the elements in order to get different permutations
    // and then give a recursive call for the next index
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solvePermutation(nums, answer, index + 1);
        // Now in order to start for the next index's element you need to back track in
        // order to reach that same state from which you started
        // For example if you are at {1,3,2} state u need to get back to {1,2,3} stage in
        // order to start the cycle for {2,1,3}
        swap(nums[index], nums[i]);
    }
}

void nextPermutation(vector<int> &nums)
{
    vector<vector<int>> answer;
    vector<int> nextIndex;
    int index = 0;
    solvePermutation(nums, answer, index);
    for (int i = 0; i < answer.size() - 1; i++)
    {
        if (nums[0] == answer[0][i])
        {
            cout << answer[0][i] << endl;
            nums = answer[i + 1];
        }
    }
    cout << endl;
    cout << "Final Answer :-";
    cout << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> nums = {{1, 2, 3}};
    nextPermutation(nums);
}
// Implemented by Kritagya Kumra