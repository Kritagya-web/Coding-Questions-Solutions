// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
int Nth_Term(int num)
{
    int term = 3 * num + 7;
    return term;
}
int main()
{
    int n, result;
    cout << "Enter the corresponding value of n" << endl;
    cin >> n;
    result = Nth_Term(n);
    cout << "Ans is " << result;
    return 0;
}
// Implemented by Kritagya Kumra
