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
// arrange but orderd not mantained
void arrange(int a[], int n)
{
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        if (a[l] >= 0 && a[h] < 0)
        {
            int temp = a[l];
            a[l] = a[h];
            a[h] = temp;
            l++;
            h--;
        }
        else if (a[l] >= 0)
        {

            h--;
        }
        else
        {
            l++;
        }
    }
}

void arrange2(int a[], int n)
{
    int j = 0;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            int k = i;
            temp = a[i];
            while (k > j)
            {
                a[k] = a[k - 1];
                k--;
            }
            a[j] = temp;
            j++;
        }
    }
}

int main()
{
    // int N = 9;
    // int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    // // int N = 4;
    // int arr[] = {-3, 3, -2, 2};
    // int arr[] = { -3, 1, 0, -2};
    int N = 5;
    int arr[] = {-5, -3, -4, -2, 3, 5, 5};

    Display(arr, N);
    // arrange(arr, N);
    cout << "Vishal" << endl;
    // Display(arr, N);
    arrange2(arr, N);
    Display(arr, N);

    return 0;
}