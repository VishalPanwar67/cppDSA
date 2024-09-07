// Anti Diagonal Traversal of Matrix
#include <iostream>
#include <vector>
using namespace std;

void DisplayMatrix(vector<vector<int>> matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void DisplayVector(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> antiDiagonalPattern(vector<vector<int>> matrix)
{
    // Code here
    int n = matrix.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int r = 0, c = i;
        while (r < n && c >= 0)
        {
            ans.push_back(matrix[r][c]);
            r++;
            c--;
        }
    }
    for (int i = 1; i < n; i++)
    {
        int r = i, c = n - 1;
        while (r < n && c >= 0)
        {
            ans.push_back(matrix[r][c]);
            r++;
            c--;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{3, 2, 3}, {4, 5, 1}, {7, 8, 9}};
    DisplayMatrix(matrix);
    vector<int> res = antiDiagonalPattern(matrix);
    DisplayVector(res);
    return 0;
}