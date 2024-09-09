// Commorn in 3 array
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    unordered_map<int, int> m1, m2, m3;
    vector<int> v;
    for (int i = 0; i < n1; i++)
        m1[A[i]]++;
    for (int i = 0; i < n2; i++)
        m2[B[i]]++;
    for (int i = 0; i < n3; i++)
        m3[C[i]]++;

    for (int i = 0; i < n1; i++)
    {
        if (m1[A[i]] > 0 && m2[A[i]] > 0 && m3[A[i]] > 0)
        {
            v.push_back(A[i]);
            // Stopping to print the duplicates
            m1[A[i]] = 0;
        }
    }

    return v;
}

int main()
{
    // int n1 = 6;
    // int A[] = {1, 5, 10, 20, 40, 80};
    // int n2 = 5;
    // int B[] = {6, 7, 20, 80, 100};
    // int n3 = 8;
    // int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = 3;
    int A[] = {3, 3, 3};
    int n2 = 3;
    int B[] = {3, 3, 3};
    int n3 = 3;
    int C[] = {3, 3, 3};
    // commonElements(A, B, C, n1, n2, n3);
    vector<int> res = commonElements(A, B, C, n1, n2, n3);
    if (res.size() == 0)
    {
        cout << -1;
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}