// Implemented by Kritagya Kumra
#include <iostream>
#include <vector>
using namespace std;

void print(string str, vector<string> &answer, int index)
{
    cout << "For index " << index << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
}
void solvePermutation(string str, vector<string> &answer, int index)
{
    print(str, answer, index);
    // Base case :- when index crosses the num's last element
    if (index >= str.length())
    {
        answer.push_back(str);
        return;
    }
    // Start iterating the nums from index to nums.size()-1 and
    // start swapping the elements in order to get different permutations
    // and then give a recursive call for the next index
    for (int i = index; i < str.length(); i++)
    {
        swap(str[index], str[i]);
        solvePermutation(str, answer, index + 1);
        // Now in order to start for the next index's element you need to back track in
        // order to reach that same state from which you started
        // For example if you are at {1,3,2} state u need to get back to {1,2,3} stage in
        // order to start the cycle for {2,1,3}
        swap(str[index], str[i]);
    }
}
vector<string> generatePermutations(string &str)
{
    vector<string> answer;
    int index = 0;
    solvePermutation(str, answer, index);
    return answer;
}
int main()
{
    string str = "abc";
    vector<string> answer;
    answer = generatePermutations(str);

    cout << endl;
    cout << "Final Answer :-";
    cout << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
}
// Implemented by Kritagya Kumra