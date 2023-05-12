// Implemented by Kritagya Kumra
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int n = num;
    /*
    if(num>100){
        cout<<"The number "<<num<<" has "<<(num/100)<<" -> 100 Rs. notes."<<endl ;
        num=num-(num/100)*100;
    }
    if(num>50){
        cout<<"The number "<<num<<" has "<<(num/50)<<" -> 50 Rs. notes."<<endl ;
        num=num-(num/50)*50;
    }
    if(num>10){
        cout<<"The number "<<num<<" has "<<(num/10)<<" -> 10 Rs. notes."<<endl ;
        num=num-(num/10)*10;
    }
    if(num>1){
        cout<<"The number "<<num<<" has "<<(num/1)<<" -> 1 Rs. notes."<<endl ;
        num=num-(num/1)*1;
    }
    return 0;*/

    switch (true)
    {
    case true:
        cout << "The number " << n << " has " << (num / 100) << " -> 100 Rs. notes." << endl;
        num = num - (num / 100) * 100;
        cout << "The number " << n << " has " << (num / 50) << " -> 50 Rs. notes." << endl;
        num = num - (num / 50) * 50;
        cout << "The number " << n << " has " << (num / 10) << " -> 10 Rs. notes." << endl;
        num = num - (num / 10) * 10;
        cout << "The number " << n << " has " << (num / 1) << " -> 1 Rs. notes." << endl;
        num = num - (num / 1) * 1;
        break;
    }
    return 0;
}
// Implemented by Kritagya Kumra