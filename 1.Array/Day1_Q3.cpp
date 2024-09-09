#include <iostream>
using namespace std;


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
      int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int kthSmallest(int arr[], int l, int r, int k)
{
    quickSort(arr, 0, r);
    return arr[k - 1];
}

void Display(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // int arr[] = {12, 4, 5, 6, 7, 3, 1, 15};
    // int arr[] = {7, 10, 4, 20, 15};
    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    Display(arr, size);

    // quickSort(arr, 0, size - 1);
    cout << kthSmallest(arr, 0, size - 1, 3) << endl;

    cout << "Sorted array: ";
    Display(arr, size);

    return 0;
}
