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

int doUnion(int a[], int n, int b[], int m)
{
    int unionNum;
    if (n >= m)
    {

        unionNum = n;

        for (int i = 0; i < m; i++)
        {
            int flag = 0;
            for (int j = 0; j < n; j++)
            {
                if (b[i] == a[j])
                {
                    break;
                }
                else
                {
                    flag++;
                }
            }

            if (flag == n)
            {

                unionNum++;
            }
        }

        return unionNum;
    }
    else
    {

        unionNum = m;
        for (int i = 0; i < n; i++)
        {
            int flag = 0;
            for (int j = 0; j < m; j++)
            {
                if (a[i] == b[j])
                {
                    break;
                }
                else
                {
                    flag++;
                }
            }

            if (flag == m)
            {

                unionNum++;
            }
        }

        return unionNum;
    }
}

int main()
{
    // int n = 5, m = 3;
    // int a[] = {1, 2, 3, 4, 5};
    // int b[] = {1, 2, 3};
    int n = 6, m = 6;
    int a[] = {85, 25, 1, 32, 54, 6};
    int b[] = {85, 2,1,32,54,6};
    cout << doUnion(b, m, a, n);

    return 0;
}