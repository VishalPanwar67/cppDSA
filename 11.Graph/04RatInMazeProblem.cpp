#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printVector(vector<vector<int>> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int newx, int newy, vector<vector<int>> &mat, vector<vector<bool>> &visited, int n)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (visited[newx][newy] != 1 && mat[newx][newy] != 0))
    {
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int>> &mat, int n, vector<string> &ans,
           vector<vector<bool>> &visited, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;
    if (isSafe(x - 1, y, mat, visited, n))
    {
        solve(x - 1, y, mat, n, ans, visited, path + 'U');
    }
    if (isSafe(x + 1, y, mat, visited, n))
    {
        solve(x + 1, y, mat, n, ans, visited, path + 'D');
    }
    if (isSafe(x, y - 1, mat, visited, n))
    {
        solve(x, y - 1, mat, n, ans, visited, path + 'L');
    }
    if (isSafe(x, y + 1, mat, visited, n))
    {
        solve(x, y + 1, mat, n, ans, visited, path + 'R');
    }
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &mat)
{
    vector<string> ans;
    int n = mat.size();
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";
    if (mat[0][0] == 0)
    {
        ans.push_back("Not Possible");
        return ans;
    }

    solve(0, 0, mat, n, ans, visited, path);

    if (ans.size() == 0)
    {
        ans.push_back("Not Possible");
    }
    return ans;
}

void printAns(vector<string> ans)
{

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    printVector(mat);

    vector<string> ans = findPath(mat);
    printAns(ans);

    cout << "Seocnd" << endl;
    vector<vector<int>> mat2 = {
        {1, 0},
        {1, 0}};

    printVector(mat2);
    vector<string> ans2 = findPath(mat2);

    printAns(ans2);

    return 0;
}