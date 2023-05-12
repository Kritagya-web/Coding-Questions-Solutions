// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
bool checkPalindrome(int start, string &s)
{
    int end = s.length() - 1 - start;
    if (start > end)
    {
        return true;
    }
    if (s[start] != s[end])
    {
        return false;
    }
    else
    {
        start++;
        end--;
        return checkPalindrome(start, s);
    }
}
// bool checkPalindrome(int start, int end, string &s)
// {
//     if (start > end)
//     {
//         return true;
//     }
//     if (s[start] != s[end])
//     {
//         return false;
//     }
//     else
//     {
//         start++;
//         end--;
//         return checkPalindrome(start, end, s);
//     }
// }
int main()
{
    string str = "madam";
    bool ans = checkPalindrome(0, str);
    if (ans)
    {
        cout << "String " << str << " is Palindrome";
    }
    else
    {
        cout << "String " << str << " is not Palindrome";
    }
}
// Implemented by Kritagya Kumra