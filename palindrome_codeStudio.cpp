// Implemented by Kritagya Kumra
#include <stdio.h>
#include <iostream>
using namespace std;

char toLowerCase(char ele)
{
    if (ele >= 'a' && ele <= 'z')
    {
        return ele;
    }
    else
    {
        ele = ele - 'A' + 'a';
        return ele;
    }
}
bool checkPalindrome(string s)
{
    int start = 0, end = s.size() - 1;
    while (start <= end)
    {
        int numStart = s[start];
        int numEnd = s[end];
        cout << numStart << " " << numEnd << endl;
        // cout << numStart << " ";
        // while ((numStart >= 97 && numStart <= 122) || (numStart >= 65 && numStart <= 90) || (numStart >= 48 && numStart <= 57))
        // {
        if (((numStart >= 32 && numStart <= 47) || (numStart >= 58 && numStart <= 64) || (numStart >= 91 && numStart <= 96) || (numStart >= 123 && numStart <= 126)))
        {
            start++;
            numStart = s[start];
            continue;
        }
        if (((numEnd >= 32 && numEnd <= 47) || (numEnd >= 58 && numEnd <= 64) || (numEnd >= 91 && numEnd <= 96) || (numEnd >= 123 && numEnd <= 126)))
        {
            cout << "Not executing";
            end--;
            numEnd = s[end];
            continue;
        }
        // }
        if (toLowerCase(numStart) != toLowerCase(numEnd))
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
    // cout << palindrome1[2] << endl;
    // cout << checkPalindrome(palindrome) << endl;
    cout << checkPalindrome(palindrome1);
}
// Implemented by Kritagya Kumra