// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    int answer = power(a, b / 2);
    if (b & 1)
    {
        return answer * answer * a;
    }
    else
    {
        return answer * answer;
    }
}
int main()
{
    int a, b;
    cout << "Enter the numbers" << endl;
    cin >> a >> b;
    cout << endl;
    cout << "The answer of " << a << " raised to the power " << b << " is " << power(a, b);
}
// Implemented by Kritagya Kumra