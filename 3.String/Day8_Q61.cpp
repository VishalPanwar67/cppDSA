// Next Permutation
#include <iostream>
#include <vector>
using namespace std;

vector<int> nextPermutation(int N, vector<int> arr)
{
    // code here
    int i = 0, j = arr.size() - 1, k, l;
    k = j;
    while (arr[i] < arr[i + 1] && i < N)
    {
        i++;
    }
    // cout << "i " << i << " j " << j << " k " << k << endl;
    while (arr[j] < arr[j - 1] && j > 0)
    {
        j--;
    };

    cout << "i " << i << " j " << j << " k " << k << endl;
    l=j;
    while (l < k)
    {
        swap(arr[l], arr[k]);
        l++;
        k--;
    }
    
    if (i == j && i>0)
    {
        swap(arr[i], arr[i - 1]);
    }
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return arr;
}

int main()
{
    // int n = 6;
    // vector<int> arr = {1, 2, 3, 6, 5, 4};
    // int n = 3;
    // vector<int> arr = {3, 2, 1};
    // int n = 3;
    // vector<int> arr = {1,2,3};
    int n = 5;
    vector<int> arr = {1,2,5, 3, 4};
    vector<int> ans = nextPermutation(n, arr);
    // for (int i : ans)
    // {
    //     cout << i << " ";
    // }

    return 0;
}