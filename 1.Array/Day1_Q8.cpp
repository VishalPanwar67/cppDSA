#include <iostream>
using namespace std;

void Display(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

long long maxSubarraySum(int arr[], int n)
{
    long long maxSum = arr[0];
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (maxSum < sum)
        {
            maxSum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxSum; 
}

int main()
{
    // int n = 5;
    // int a[] = {1, 2, 3, -2, 5};
    // int n = 4;
    // int a[] = {-1, -2, -3, -4};
    // int a[] = {-10, -2, -3, -4};
    int n = 9;
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubarraySum(a, n);

    return 0;
}