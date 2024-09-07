// Count of number of given string in 2D character array

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void DisplayVector(vector<vector<char>> v)
{
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{

    // vector<vector<char>> arr = {{'a', 'b', 'c'},
    //                             {'d', 'r', 'f'},
    //                             {'g', 'h', 'i'}};
    // string str = "abc";
    // DisplayVector(arr, 3, 3);

    vector<vector<char>> arr = {{'a', 'b', 'a', 'b'},
                                {'a', 'b', 'e', 'b'},
                                {'e', 'b', 'e', 'b'}};
    string str = "abe";
    DisplayVector(arr);

    return 0;
}