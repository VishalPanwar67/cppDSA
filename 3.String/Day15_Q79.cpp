#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

void print(string arr[R][C])
{
    int i{0}, j{0}, k{0};
    int ir{0}, jr{1}, kr{2};
    while (i < C)
    {
        string str = arr[ir][i] + " " + arr[jr][j] + " " + arr[kr][k];
        cout << str << endl;
        k++;
        // cout << C << " CK " << k << endl;
        if (k >= C)
        {
            // cout << "j" << endl;

            j++;
            if (arr[jr][j] == "")
            {
                // cout << "vishal" << endl;
                j++;
            }
            k = 0;
        }
        if (j >= C)
        {
            i++;
            if (arr[ir][i] == "")
            {
                // cout << "vishal" << endl;
                break;
                // i++;
            }
            j = 0;
            k = 0;
        }
    }
}

int main()
{

    // int R = 3, C = 3;
    string arr[R][C] = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};

    print(arr);

    return 0;
}