// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;

int GCD(int num1, int num2)
{
    if (num1 == 0)
    {
        return num2;
    }
    if (num2 == 0)
    {
        return num1;
    }
    while (num1 != num2)
    {
        if (num1 > num2)
        {
            num1 = num1 - num2;
        }
        else
        {
            num2 = num2 - num1;
        }
    }
    return num1;
}

int main()
{
    int a, b;
    cout << "Enter numbers to get the GCD";
    cin >> a >> b;
    int answer = GCD(a, b);
    cout << endl
         << "Answer is " << answer;
}
// Implemented by Kritagya Kumra