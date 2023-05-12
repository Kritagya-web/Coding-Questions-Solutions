// Implemented by Kritagya Kumra
#include <iostream>
#include <string>
using namespace std;

bool checkEqual(int countArray1[], int countArray2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (countArray1[i] != countArray2[i])
        {
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{
    int countArray1[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        countArray1[index]++;
    }

    int i = 0;
    int windowSize = s1.length();
    int countArray2[26] = {0};

    while (i < windowSize && i < s2.length())
    {
        int index = s2[i] - 'a';
        countArray2[index]++;
        i++;
    }
    if (checkEqual(countArray1, countArray2))
    {
        return true;
    }

    while (i < s2.length())
    {
        int newChar = s2[i] - 'a';
        countArray2[newChar]++;
        int removeOldCharacter = s2[i - windowSize] - 'a';
        countArray2[removeOldCharacter]--;
        i++;
        if (checkEqual(countArray1, countArray2))
        {
            return true;
        }
    }
    return false;
}
// Implemented by Kritagya Kumra