// 121. Best Time to Buy and Sell Stock
#include <iostream>
#include <vector>
using namespace std;

void Display(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maxProfit(int arr[], int size)
{
    int min = arr[0];
    int index{0}, max;
    for (int i = 1; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            index = i;
        }
    }
    max = min;
    for (int i = index; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max - min;
}

int maxProfit(vector<int> &prices)
{

    if (prices.empty())
    {
        return 0;
    }
    int min = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] - min > profit)
        {
            profit = prices[i] - min;
        }
        if (prices[i] < min)
        {
            min = prices[i];
        }
    }
    return profit;
}

int main()
{
    // int arr[] = {7, 1, 5, 3, 6, 4};
    // int arr[] = {7, 6, 4, 3, 1};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // Display(arr, size);
    // cout<<maxProfit(arr, size);
    // vector<int> vec = {7, 1, 5, 3, 6, 4};
    // vector<int> vec = {2, 4, 1};
    // vector<int> vec = {2, 1, 2, 1, 0, 1, 2};
    vector<int> vec = {3, 2, 6, 5, 0, 3};
    cout << maxProfit(vec);
    return 0;
}