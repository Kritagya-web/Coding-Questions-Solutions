
// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
int fact(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int nCr(int n, int r)
{
    int result = 0;
    int num = fact(n);
    int dem = fact(r) * fact(n - r);
    result = num / dem;
    return result;
}
int main()
{
    int r, n, result;
    cout << "Enter the corresponding value for r and n" << endl;
    cin >> r >> n;
    result = nCr(n, r);
    cout << "Ans is " << result;
    return 0;
}
// Implemented by Kritagya Kumra