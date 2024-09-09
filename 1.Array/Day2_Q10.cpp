// Minimum number of jumps

#include <iostream>
#include "BaseArr.cpp"
using namespace std;

int minJumps(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    if (arr[0] == 0)
    {
        return -1;
    }
    int maxReach = arr[0];
    int steps = arr[0];
    int jumps = 0;
    for (int i = 1; i < n - 1; i++)
    {
        steps--;
        if (maxReach < arr[i] + i)
        {
            maxReach = arr[i] + i;
        }

        if (steps == 0)
        {
            jumps++;
            steps = maxReach - i;
            if (steps == 0)
            {
                return -1;
            }
        }
    }
    return jumps + 1;
}

int main()
{
    // int N = 11;
    // int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int N = 6;
    int arr[] = {1, 4, 3, 2, 6, 7};
    Display(arr, N);
    cout << minJumps(arr, N);
    return 0;
}