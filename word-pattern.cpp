// Implemented by Kritagya Kumra
#include <cstring>
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        char str[100];
        char *ptr;
        ptr = strtok(s, " , ");

        for (int i = 0; i < pattern.length(); i++)
        {
            int countOfPattern = count(pattern.begin(), pattern.end(), pattern[i]);
            int countOfPattern = count(ptr.begin(), ptr.end(), ptr[i]);
            if (countOfPattern != countOfPattern)
            {
                return false;
            }
            ptr = strtok(NULL, " , ");
        }
        return true;
    }
};
// Implemented by Kritagya Kumra