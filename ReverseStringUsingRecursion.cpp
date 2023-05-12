// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
// void reverse(int start, int end, string &s)
// {
//     if (start > end)
//     {
//         return;
//     }
//     swap(s[start], s[end]);
//     reverse(start + 1, end - 1, s);
// }
// int main()
// {
//     string str = "Tech Geek";
//     reverse(0, str.length() - 1, str);
//     cout << str;
// }

void reverse(int start, string &s)
{
    int end = s.length() - 1 - start;
    if (start > end)
    {
        return;
    }
    swap(s[start], s[end]);
    reverse(start + 1, s);
}
int main()
{
    string str = "Tech Geek";
    reverse(0, str);
    cout << str;
}
// Implemented by Kritagya Kumra