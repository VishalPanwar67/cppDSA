#include <iostream>
#include "BaseArr.cpp"
using namespace std;

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here

}
// long long int inversionCount(long long arr[], long long N)
// {
//     // Your Code Here
//     long long inv = 0;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = i + 1; j < N; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 inv++;
//             }
//         }
//     }
//     return inv;
// }

int main()
{
    long long n = 5;
    long long arr[] = {2, 4, 1, 3, 5};
    // long long n = 3;
    // long long arr[] = {10, 10, 10};
    // Display(arr, n);
    cout << inversionCount(arr, n);
    return 0;
}