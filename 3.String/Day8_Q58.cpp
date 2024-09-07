// Split the Binary string into two substring with equal 0’s and 1’s

#include <iostream>
#include <string.h>
using namespace std;

int maxSubStr(string str)
{

    int n = str.length();
    if (n == 0)
    {
        return -1;
    }
    int subCount{-1}, zeroCount{0}, oneCount{0};
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
        if (zeroCount == oneCount)
        {
            subCount++;
        }
        cout << oneCount << " Vishal " << zeroCount << endl;
    }
    if (oneCount == zeroCount)
    {
        return subCount + 1;
    }
    return -1;
}

int main()
{
    // string str = "0100110101";
    // string str = "0000000000";
    string str = "001110010";
    cout << str << endl;
    cout << maxSubStr(str);
    return 0;
}