// Implemented by Kritagya Kumra
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool isValidSerialization(string preorder)
{
    int nodes = 1;
    preorder += ',';
    cout << preorder << endl;
    for (int i = 0; i < preorder.size(); i++)
    {
        if (preorder[i] != ',')
            continue; // comma seperated values of nodes
        nodes--;      // after taking each node decrease value of left nodes
        if (nodes < 0)
            return false;
        if (preorder[i - 1] != '#')
            nodes += 2; // if current node is not null means it will 2 childs si increase by 2;
        cout << preorder[i] << " " << nodes << endl;
    }
    return nodes == 0;
}
int main()
{
    string str = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    bool isPreorder = isValidSerialization(str);
    if (isPreorder)
    {
        cout << "correct";
    }
    else
    {
        cout << "Incorrect";
    }
}
// Implemented by Kritagya Kumra