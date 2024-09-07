// Array Pair Sum Divisibility Problem

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool canPair(vector<int> nums, int k)
{
    // Code here.
    map<int, int> store;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int cur = nums[i] % k;
        int need = (k - cur) % k;
        if (store.count(need))
        {
            --store[need];
            if (store[need] == 0)
            {
                store.erase(need);
            }
        }
        else
        {
            ++store[cur];
        }
    }
    return store.size() == 0;
}

int main()
{
    // long long int n = 4, k = 6;
    // long long int arr[] = {9,5,7,3};
    int k = 4;
    vector<int> arr[] = {4, 4, 4};
    canPair(arr, k);
    return 0;
}

// https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1