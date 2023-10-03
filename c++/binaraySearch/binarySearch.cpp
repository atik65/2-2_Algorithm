#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x);

int main()
{

    int testArr[] = {2, 5, 8, 36, 45, 87, 96, 104, 336};
    int length = sizeof(testArr) / sizeof(testArr[0]);
    int x = 4;

    int index = binarySearch(testArr, 0, length - 1, x);

    if (index == -1)
        cout << "Item not found in given array" << endl;
    else
    {
        cout << "Item found at position " << index + 1 << endl;
    }

    return 0;
}

int binarySearch(int arr[], int l, int r, int x)
{

    if (r < l)
        return -1;

    int mid = (l + r) / 2;

    if (x == arr[mid])
        return mid;

    if (x < arr[mid])
        return binarySearch(arr, l, mid - 1, x);

    return binarySearch(arr, mid + 1, r, x);
}