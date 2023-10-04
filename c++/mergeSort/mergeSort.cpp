#include <iostream>
using namespace std;

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main()
{
    int testArr[] = {8, 6, 45, 36, 1, 25, 3, 17, 2, 3};
    // int testArr[] = {12, 11, 13, 5, 6, 7};
    // int testArr[] = {100, 5, 69, 25, 3, 11, 7, 6, 200, 36, 15, 2};

    int length = sizeof(testArr) / sizeof(testArr[0]);

    cout << "Printing the array before sorting: ";
    for (int i = 0; i < length; i++)
    {
        cout << testArr[i] << " ";
    }
    cout << endl;

    mergeSort(testArr, 0, length - 1);

    cout << "Printing the array after sorting: ";
    for (int i = 0; i < length; i++)
    {
        cout << testArr[i] << " ";
    }
    cout << endl;

    return 0;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int leftSubArray[n1];
    int rightSubArray[n2];

    for (int i = 0; i < n1; i++)
    {
        leftSubArray[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        rightSubArray[j] = arr[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {

        if (leftSubArray[i] < rightSubArray[j])
        {
            arr[k] = leftSubArray[i];
            i++;
        }
        else
        {
            arr[k] = rightSubArray[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = leftSubArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightSubArray[j];
        j++;
        k++;
    }
};