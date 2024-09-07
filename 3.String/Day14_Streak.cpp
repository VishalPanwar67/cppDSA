#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int isPossible(int N, int coins[])
{
    set<int> sums;
    sums.insert(0);

    for (int i = 0; i < N; ++i)
    {
        set<int> store = sums;
        for (auto it : store)
        {
            int t = it + coins[i];
            if (t % 20 == 0 || t % 24 == 0)
            {
                return 1;
            }
            // cout << " it " << it << endl;
            // cout << " t " << t << endl;
            sums.insert(it + coins[i]);
        }
    }
    return sums.find(2024) != sums.end();
}

int main()
{
    int n = 8;
    int coins[] = {5, 8, 9, 10, 14, 2, 3, 5};
    cout << isPossible(n, coins);

    return 0;
}