// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
// Returns true if the binary representation of `n` is a palindrome
bool isPalindrome(long long n)
{
    // `rev` stores reverse of a binary representation of `n`
    long long rev = 0;
    long long k = n;
    // do till all bits of `n` are processed
    while (k)
    {
        rev = rev << 1 | k & 1;
        k = k >> 1;
    }
    return rev == n;
    // Returns true if `reverse(n)` is the same as `n`
}

int main()
{
    int n = 9; // 1001

    if (isPalindrome(n))
    {
        cout << n << " is a palindrome";
    }
    else
    {
        cout << n << " is not a palindrome";
    }

    return 0;
}
// Implemented by Kritagya Kumra