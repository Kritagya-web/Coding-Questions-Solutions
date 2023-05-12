// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
string addStrings(string num1, string num2)
{
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    string answer = "";
    int carry = 0;
    char value;
    int sum = 0;
    while (i >= 0 && j >= 0)
    {
        sum += carry;
        if (i > 0)
            sum = sum + num1[i] - 48;
        if (j > 0)
            sum = sum + num2[j] - 48;
        value = (sum % 10) + 48;
        answer += value;
        carry = sum / 10;
        i--;
        j--;
    }
    value = carry + 48;
    if (carry)
        answer = answer + value;
    reverse(answer.begin(), answer.end());
}
int main()
{
    string num1, num2;
    cout << "Enter your first number " << endl;
    cin >> num1;
    cout << "Enter your second number " << endl;
    cin >> num2;
    cout << "The answer is " << addStrings(num1, num2);
}
// Implemented by Kritagya Kumra