// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
int Sum_Array(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
void Input_Array(int arr[], int n)
{
    cout << "Enter No's" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
int main()
{
    int elements[10] = {0}, n, result;
    cout << "Enter size" << endl;
    cin >> n;
    Input_Array(elements, n);
    result = Sum_Array(elements, n);
    cout << "Ans is " << result;
    return 0;
}

// Implemented by Kritagya Kumra