#include <iostream>
using namespace std;

void quickSort(int arr[], int l, int r);
int partition(int arr[], int l, int r);
void swap(int arr[], int a, int b);

int main()
{
    // int testArr[] = {8, 6, 45, 36, 1, 25, 3, 17, 2, 3};
    int testArr[] = {100, 5, 69, 25, 3, 11, 7, 6, 200, 36, 15, 2};

    int length = sizeof(testArr) / sizeof(testArr[0]);

    cout << "Printing the array before sorting: ";
    for (int i = 0; i < length; i++)
    {
        cout << testArr[i] << " ";
    }
    cout << endl;

    quickSort(testArr, 0, length - 1);

    cout << "Printing the array after sorting: ";
    for (int i = 0; i < length; i++)
    {
        cout << testArr[i] << " ";
    }
    cout << endl;

    return 0;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pivotPosition = partition(arr, l, r);
        quickSort(arr, l, pivotPosition - 1);
        quickSort(arr, pivotPosition + 1, r);
    }
}

int partition(int arr[], int l, int r)
{
    int i = l;
    int j = r;
    int pivot = arr[l];

    while (i < j)
    {

        while (arr[i] <= pivot && i < r)
            i++;

        while (arr[j] >= pivot && j > l)
            j--;

        if (i < j)
            swap(arr, i, j);
    }

    swap(arr, l, j);
    return j;
}

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}