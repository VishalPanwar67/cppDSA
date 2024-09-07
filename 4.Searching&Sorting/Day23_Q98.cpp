#include <iostream>
#include <bits/stdc++.h>
using namespace std;




long long int inversionCount(long long arr[], long long N)
{
    // Your Code
    // 100 / 117
    long long i{0}, j{i + 1};
    long long int inv{0};

    while (i < N - 1)
    {
        if (arr[i] > arr[j])
        {
            inv++;
        }
        j++;
        if (j >= N)
        {
            i++;
            j = i + 1;
        }
    }
    return inv;
}

int main()
{
    long long N = 5;
    long long arr[] = {2, 4, 1, 3, 5};
    cout << inversionCount(arr, N) << endl;
    return 0;
}