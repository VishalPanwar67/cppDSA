#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Display(vector<vector<int>> matrix, int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void DisplayV(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N)
{
    // Your code here
    unordered_map<string, int> store;
    vector<int> ans;
    for (int i = 0; i < M; i++)
    {
        string tempCheak = "";
        for (int j = 0; j < N; j++)
        {
            tempCheak += matrix[i][j] + '0';
        }
        if (store.find(tempCheak) != store.end())
        {
            ans.push_back(i);
        }
        store[tempCheak] = i;
    }
    return ans;
}

int main()
{
    int M = 9, N = 4;
    vector<vector<int>> matrix = {{0, 1, 1, 0},
                                  {1, 0, 0, 1},
                                  {1, 0, 0, 1},
                                  {1, 0, 0, 1},
                                  {0, 1, 1, 0},
                                  {1, 1, 0, 0},
                                  {0, 1, 1, 0},
                                  {0, 1, 1, 0},
                                  {0, 0, 1, 1}};

    Display(matrix, M, N);

    vector<int> ans = repeatedRows(matrix, M, N);
    DisplayV(ans);

    return 0;
}