#include <iostream>
#include <string>
using namespace std;

string rev(string str)
{
    string temp = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        temp += str[i];
    }
    return temp;
}

int main()
{
    string str;
    getline(cin, str);
    cout << str << endl;
    cout << rev(str);

    return 0;
}