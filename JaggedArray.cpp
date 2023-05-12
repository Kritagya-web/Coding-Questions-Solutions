// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;
int main()
{
    int row = 5;
    int count = rand() % 10;
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[count];
    }
}
// Implemented by Kritagya Kumra