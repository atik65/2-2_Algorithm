
#include <iostream>
using namespace std;

// function for finding max value
int max(int a, int b) { return (a > b) ? a : b; }

// function for knapSack operation
int knapSack(int n, int weight, int w[], int v[])
{

    int K[n + 1][weight + 1];

    for (int i = 0; i <= n; i++)
    {

        for (int j = 0; j <= weight; j++)
        {

            if (i == 0 || j == 0)
            {
                K[i][j] = 0;
            }
            else if (w[i - 1] <= j)
            {
                K[i][j] = max(v[i - 1] + K[i - 1][j - w[i - 1]], K[i - 1][j]);
            }
            else
            {

                K[i][j] = K[i - 1][j];
            }
        }
    }

    return K[n][weight];
}

int main()
{
    int n, weight;
    cout << "Enter n:" << endl;
    cin >> n;

    cout << "Enter max weight of knapSack: " << endl;
    cin >> weight;

    int val[n];
    cout << "Enter values of items: " << endl;
    for (int i = 0; i < n; i++)
        cin >> val[i];

    int wt[n];
    cout << "Enter Weights of items: " << endl;
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Maximum result from the knapSack is: " << knapSack(n, weight, wt, val);

    return 0;
}