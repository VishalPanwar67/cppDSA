// Word Wrap Problem [VERY IMP].
#include <iostream>
#include <vector>
using namespace std;

int solveWordWrap(vector<int> nums, int k)
{
    // Code here
    int n = nums.size();
    int sum{0}, ans{0}, flag{0}, i{0};
    while (i < n)
    {
        cout << "sum + nums[i] + 1:  " << sum + nums[i] + 1 << " < " << k << endl;
        if ((sum + nums[i]) < k)
        {

            sum += nums[i] + 1;
            i++;
            cout << " Vishal sum " << sum << " flag " << flag << endl;
        }
        else
        {
            cout << "(k - sum) " << (k - sum) << endl;
            sum -= 1;
            ans += ((k - sum) * (k - sum));
            sum = 0;
            cout << "ans " << ans << " sum " << sum << endl;

            flag = 0;
        }
        cout << " Panwar i " << i << " n " << n << endl;
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 2, 2, 5};
    int k = 6;
    // vector<int> arr = {3, 2, 2};
    // int k = 4;
    cout << solveWordWrap(arr, k);

    return 0;
}