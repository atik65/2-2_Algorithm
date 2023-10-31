#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char id;
    int deadLine;
    int profit;

    Job(char id, int deadLine, int profit)
    {
        this->id = id;
        this->deadLine = deadLine;
        this->profit = profit;
    }
};

int min(int a, int b) { return (a < b) ? a : b; }

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

int jobSequence(Job arr[], int n)
{
    sort(arr, arr + n, cmp);

    int result[n];
    bool slot[n];
    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        slot[i] = false;
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = min(n, arr[i].deadLine) - 1; j >= 0; j--)
        {

            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            totalProfit += arr[result[i]].profit;
            cout << arr[result[i]].id << "";
        }
    }
    cout << endl;
    cout << "Total profit = ";

    return totalProfit;
}

int main()
{

    Job arr[] = {{'a', 2, 100},
                 {'b', 1, 19},
                 {'c', 2, 27},
                 {'d', 1, 25},
                 {'e', 3, 15}};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs= ";

    // Function call
    cout << jobSequence(arr, n);
    cout << endl;

    return 0;
}