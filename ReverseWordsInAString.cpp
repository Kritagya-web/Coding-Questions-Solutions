// Implemented by Kritagya Kumra
#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s)
{
    int end = s.length() - 1, space = 0;
    s.insert(0, " ");
    int count = end;
    string temp = "";
    while (count != -1)
    {
        if (s[count] != ' ')
        {
            count--;
            continue;
        }
        else
        {
            space = count;
            for (int i = space + 1; i <= end; i++)
            {
                if (s[i] == ' ')
                {
                    continue;
                }
                temp.push_back(s[i]);
            }
            temp.push_back(' ');
            end = space - 1;
            count--;
        }
    }
    return temp;
}
int main()
{
    string s = "the sky is blue";
    string s1 = "  hello world  ";
    string s2 = "a good   example";
    string ans1 = reverseWords(s);
    string ans2 = reverseWords(s1);
    string ans3 = reverseWords(s2);
    cout << endl
         << endl;
    cout << ans1 << endl
         << ans2 << endl
         << ans3;
}
// Implemented by Kritagya Kumra