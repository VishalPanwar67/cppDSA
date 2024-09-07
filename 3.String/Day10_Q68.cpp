// Count of number of given string in 2D character array

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void DisplayVector(vector<vector<char>> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int findOccurrence(vector<vector<char>> &mat, string target)
{
    int n = mat.size(), sl = target.length();
    int v{0}, temp{0}, ans{0};
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (target[0] == mat[r][c])
            {
                // cout << " (0,2) loop 1 " << target[0] << r << c << endl;
                // cout << " temp 1 " << temp << endl;
                for (int i = r; i < n && v < sl; i++, v++)
                {
                    // cout << target[v] << " = " << mat[i][c] << endl;
                    if (target[v] == mat[i][c])
                    {
                        temp++;
                    }
                    else
                    {
                        temp = 0;
                        break;
                    }
                }

                // cout << " temp 1 " << temp << endl;
                // cout << " sl " << sl << endl;
                if (temp == sl)
                {

                    ans++;
                    // cout << " ans 1 " << ans << endl;
                }
                temp = 0;
                v = 0;
            }
            if (target[0] == mat[r][c])
            {
                // cout << " (0,2) loop 2 " << target[0] << r << c << endl;
                // cout << " temp 2 " << temp << endl;
                for (int i = r, v = 0; i >= 0 && v < sl; i--, v++)
                {
                    // cout << target[v] << " = " << mat[i][c] << endl;
                    if (target[v] == mat[i][c])
                    {
                        temp++;
                    }
                    else
                    {
                        temp = 0;
                        break;
                    }
                }
                // cout << " temp 2 " << temp << endl;
                // cout << " sl " << sl << endl;
                if (temp == sl)
                {
                    ans++;

                    // cout << " ans 2 " << ans << endl;
                }
                temp = 0;
                v = 0;
            }
            if (target[0] == mat[r][c])
            {
                // cout << " loop 3 " << target[0] << r << c << endl;
                for (int i = c; i < n && v < sl; i++, v++)
                {
                    if (target[v] == mat[r][i])
                    {
                        temp++;
                    }
                    else
                    {
                        temp = 0;
                        break;
                    }
                }
                if (temp == sl)
                {

                    ans++;
                    // cout << " ans 3 " << ans << endl;
                }
                temp = 0;
                v = 0;
            }
            if (target[0] == mat[r][c])
            {
                // cout << " loop 4 " << target[0] << r << c << endl;
                // cout << " temp 4 " << temp << endl;
                for (int i = c, v = 0; i >= 0 && v < sl; i--, v++)
                {
                    // cout << target[v] << " = " << mat[i][c] << endl;
                    if (target[v] == mat[r][i])
                    {
                        temp++;
                    }
                    else
                    {
                        temp = 0;
                        break;
                    }
                }
                // cout << " temp 4 " << temp << endl;
                // cout << " sl " << sl << endl;
                if (temp == sl)
                {
                    ans++;
                    // cout << " ans 4 " << ans << endl;
                }
                temp = 0;
                v = 0;
            }
        }
    }
    return ans;
}

int main()
{

    vector<vector<char>> arr = {{'D', 'D', 'D', 'G', 'D', 'D'},
                                {'B', 'B', 'D', 'E', 'B', 'S'},
                                {'B', 'S', 'K', 'E', 'B', 'K'},
                                {'D', 'D', 'D', 'D', 'D', 'E'},
                                {'D', 'D', 'D', 'D', 'D', 'E'},
                                {'D', 'D', 'D', 'D', 'D', 'G'}};
    string str = "GEEKS";
    // vector<vector<char>> arr = {{'B', 'B', 'M', 'B', 'B', 'B'},
    //                             {'C', 'B', 'A', 'B', 'B', 'B'},
    //                             {'I', 'B', 'G', 'B', 'B', 'B'},
    //                             {'G', 'B', 'I', 'B', 'B', 'B'},
    //                             {'A', 'B', 'C', 'B', 'B', 'B'},
    //                             {'M', 'C', 'I', 'G', 'A', 'M'}};
    // string str = "MAGIC";

    DisplayVector(arr);
    cout << findOccurrence(arr, str);

    return 0;
}