// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;

int sqrt_part_1(int N)
{
    int start = 0;
    int end = N;
    long long int mid = start + (end - start) / 2;
    long long int answer = -1;
    while (start <= end)
    {
        long long int square = mid * mid;
        if (square == N)
        {
            return mid;
        }
        if (square < N)
        {
            answer = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return answer;
}
double getprecision(int n, int prec, int tempSol)
{
    double factor = 1;
    double answer = tempSol;
    for (int i = 0; i < prec; i++)
    {
        factor = factor / 10;
        for (double i = answer; i * i < n; i = i + factor)
        {
            answer = i;
        }
    }
    return answer;
}
int main()
{
    int n;
    cout << "Enter a number\n";
    cin >> n;
    int partOne = sqrt_part_1(n);
    double partTwo = getprecision(n, 3, partOne);
    cout << "Answer is " << partTwo;
    return 0;
}
// Implemented by Kritagya Kumra