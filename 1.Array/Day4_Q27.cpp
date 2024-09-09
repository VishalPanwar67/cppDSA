//find Subset or not??


#include <iostream>
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

string isSubset(int a1[], int a2[], int n, int m)
{
    sort(a1, a1 + n);
    sort(a2, a2 + m);

    int i{0}, j{0};
    while (i < n && j < m)
    {
        if (a1[i] == a2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (j >= m)
    {
        return "Yes";
    }
    return "No";
}

int main()
{
    int a1[] = {11, 7, 1, 13, 21, 3, 7, 3};
    int a2[] = {11, 3, 7, 1, 7};
    int s1 = sizeof(a1) / sizeof(a1[0]);
    int s2 = sizeof(a2) / sizeof(a2[0]);
    isSubset(a1, a2, s1, s2);
    return 0;
}