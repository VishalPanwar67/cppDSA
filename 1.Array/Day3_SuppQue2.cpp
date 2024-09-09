// Candy

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void Display(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int minCandy(int ratings[], int N)
{
    // code here
    int candies = N;
    int temp = 0;
    // cout << candies << endl;
    if (N == 1)
    {
        return candies;
    }
    if (ratings[0] > ratings[1])
    {
        candies++;
    }
    for (int i = 1; i < N; i++)
    {
        int j = i + 1;
        if (j >= N)
        {
            j--;
        }
        if (ratings[i - 1] < ratings[i] || ratings[j] < ratings[i])
        {
            temp++;
            candies += temp;
        }
        else
        {
            temp = 0;
        }
        cout << "temp" << temp << endl;
    }
    return candies;
}

int minCandy2(int ratings[], int N)
{
    vector<int> v(N, 1);
    int candies = 0;
    for (int i = 1; i < N; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            v[i] = v[i - 1] + 1;
        }
    }
    for (int i = N - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            v[i] = max(v[i], v[i + 1] + 1);
        }
    }
    for (int i = 0; i < N; i++)
    {
        candies += v[i];
    }
    return candies;
}

int main()
{

    // int n = 3;
    // int arr[] = {1, 0, 2};

    // int n = 3;
    // int arr[] = {1, 2, 2};
    // int n = 0;
    // int arr[] = {};
    // int n = 1;
    // int arr[] = {16827};
    // int n = 5;
    // int arr[] = {1,1,2,0,4};
    int n = 10;
    int arr[] = {11942, 4827, 5436, 32391, 14604, 3902, 153, 292, 12382, 17421};
    Display(arr, n);
    // minCandy(arr, n);
    // cout << minCandy(arr, n);
    cout << minCandy2(arr, n);
    return 0;
}

// There are N children standing in a line.Each child is assigned a rating value given in the integer array ratings.You are giving candies to these children subjected to the following requirements :

// 1> Each child must have atleast one candy.
// 2> Children with a higher rating than it's neighbours get more candies than neighbors. Return the minimum number of candies you need to have to distribute.