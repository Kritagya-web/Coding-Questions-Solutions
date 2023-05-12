// Implemented by Kritagya Kumra
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

bool toLowerCase(char ele)
{
    if (ele >= 'a' && ele <= 'z')
    {
        return true;
    }
    else
    {

        return false;
    }
}
char convert_lower(char ele)
{
    ele = ele - 'A' + 'a';
    return ele;
}
bool checkPalindrome(string s)
{
    int i = 0;

    while (i <= s.size() - 1)
    {
        int numStart = s[i];

        if (((numStart >= 32 && numStart <= 47) || (numStart >= 58 && numStart <= 64) || (numStart >= 91 && numStart <= 96) || (numStart >= 123 && numStart <= 126)))
        {
            s.erase(i, 1);
        }

        if (!(toLowerCase(s[i])))
        {
            s[i] = convert_lower(s[i]);
        }
        i++;
    }
    int start = 0, end = s.size() - 1;
    while (start <= end)
    {

        if (s[start] != s[end])
        {
            return false;
        }
        else
        {
            start++, end--;
        }
    }
    return true;
}
int main()
{
    string palindrome = "Noon";
    // string palindrome1 = "maf@da%%%%#&m";
    string palindrome1 = "c1 O$d@eeD o1c";
    string palindrome2 = "codingninjassajNiNgNidoc";
    // cout << palindrome1[2] << endl;
    // cout << checkPalindrome(palindrome) << endl;
    cout << endl
         << checkPalindrome(palindrome2);
}
// Implemented by Kritagya Kumra