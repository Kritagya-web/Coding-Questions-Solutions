// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
int Set_Bits(int n)
{
    int bit = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            bit++;
        }
        n = n >> 1;
    }
    return bit;
}
int main()
{
    int n1, n2, result;
    cout << "Enter the corresponding value of n1 and n2" << endl;
    cin >> n1 >> n2;
    result = Set_Bits(n1) + Set_Bits(n2);
    cout << "Ans is " << result;
    return 0;
}
// Implemented by Kritagya Kumra
