// Implemented by Kritagya Kumra
#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s)
{
    int i = 0;
    string result = "";
    while (i < s.length())
    {
        if (s[i] != s[i + 1] && i < s.length())
        {
            result += s[i];
        }
        else
        {
            i++;
        }
        i++;
    }

    return result;
}

int main()
{
    string s = "";
    cout << "Enter the string " << endl;
    cin >> s;
    cout << removeDuplicates(s);
    return 0;
}
// Implemented by Kritagya Kumra