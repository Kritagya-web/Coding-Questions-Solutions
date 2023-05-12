// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
bool Set_Bits(int n)
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
    if (bit == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int num, result;
    cout << "Enter the number" << endl;
    cin >> num;
    if (Set_Bits(num))
    {
        cout << "Number " << num << " is a power of 2" << endl;
    }
    else
    {
        cout << "Number " << num << "is not a power of 2" << endl;
    }
    return 0;
}

// Implemented by Kritagya Kumra