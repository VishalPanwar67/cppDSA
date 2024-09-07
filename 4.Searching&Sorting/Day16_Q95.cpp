// Find All Four Sum Numbers

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(arr.begin(), arr.end());

    // calculating the quadruplets:
    for (int i = 0; i < n; i++)
    {
        // avoid the duplicates while moving i:
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            // avoid the duplicates while moving j:
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            // 2 pointers:
            int m = j + 1;
            int l = n - 1;
            while (m < l)
            {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[m];
                sum += arr[l];
                if (sum == k)
                {
                    vector<int> temp = {arr[i], arr[j], arr[m], arr[l]};
                    ans.push_back(temp);
                    m++;
                    l--;

                    // smip the duplicates:
                    while (m < l && arr[m] == arr[m - 1])
                        m++;
                    while (m < l && arr[l] == arr[l + 1])
                        l--;
                }
                else if (sum < k)
                    m++;
                else
                    l--;
            }
        }
    }

    return ans;
}

void vectorDisplay(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int N = 5, m = 3;
    vector<int> arr = {0, 0, 2, 1, 1};

    vector<vector<int>> res = fourSum(arr, m);
    vectorDisplay(res);

    return 0;
}