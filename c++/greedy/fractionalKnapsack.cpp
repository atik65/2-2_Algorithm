#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int profit, weight;
    double valuePerUnitWeight;

    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
        this->valuePerUnitWeight = (double)this->profit / (double)this->weight;
    }
};

bool cmp(struct Item a, struct Item b)
{
    return a.valuePerUnitWeight > b.valuePerUnitWeight;
}

double fractionalKnapSack(int W, struct Item arr[], int N)
{
    sort(arr, arr + N, cmp);
    double finalValue = 0.0;

    for (int i = 0; i < N; i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            finalValue += arr[i].profit;
        }
        else
        {

            finalValue += arr[i].profit * (double(W) / (double)arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main()
{

    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Total profit = " << fractionalKnapSack(W, arr, N) << endl;
    return 0;
}

int main()
{

    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Total Profit = " << fractionalKnapSack(W, arr, N) << endl;

    return 0;
}