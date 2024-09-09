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

void arrange(int a[], int n)
{
    int l = 0, m = 0, h = n - 1;
    while (m <= h)
    {
        if (a[m] == 0)
        {
            swap(a[m], a[l]);
            l++;
            m++;
        }
        else if (a[m] == 1)
        {
            m++;
        }
        else
        {
            swap(a[m], a[h]);
            h--;
        }
    }
}

int main()
{
    int N = 5;
    int arr[] = {0, 2, 1, 2, 0};
    Display(arr, N);
    arrange(arr, N);
    Display(arr, N);

    return 0;
}