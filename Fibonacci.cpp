// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
void Fibonacci(int n, int a, int b)
{
    int c = 0;
    cout << a << " " << b << " ";
    while (n - 2 > 0)
    {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
        n--;
    }
}
int main()
{
    int n, a, b;
    cout << "Enter the corresponding value of no of terms of fibonacci series" << endl;
    cin >> n;
    Fibonacci(n, 0, 1);
    return 0;
}
// Implemented by Kritagya Kumra