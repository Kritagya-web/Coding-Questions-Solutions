// Implemented by Kritagya Kumra
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "kritagya";

    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char ele = str[i];
        s.push(ele);
    }

    string answer = "";

    while (!s.empty())
    {
        char ele = s.top();
        answer.push_back(ele);
        s.pop();
    }
    cout << "answer is: " << answer << endl;
    return 0;
}
// Implemented by Kritagya Kumra