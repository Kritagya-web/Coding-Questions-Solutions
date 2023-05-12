// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
string digitSwitchCase(int n);
void sayDigit(int n)
{
    if (n <= 0)
    {
        return;
    }
    int digit = n % 10;

    n = n / 10;
    sayDigit(n);
    cout << digitSwitchCase(digit) << " ";
}
string digitSwitchCase(int n)
{
    switch (n)
    {
    case 1:
        return "One";
        break;
    case 2:
        return "Two";
        break;
    case 3:
        return "Three";
        break;
    case 4:
        return "Four";
        break;
    case 5:
        return "Five";
        break;
    case 6:
        return "Six";
        break;
    case 7:
        return "Seven";
        break;
    case 8:
        return "Eight";
        break;
    case 9:
        return "Nine";
        break;
    default:
        return "wrong ans";
        break;
    }
}
int main()
{
    int n;
    cout << "Enter the digit" << endl;
    cin >> n;
    sayDigit(n);
}
// Implemented by Kritagya Kumra