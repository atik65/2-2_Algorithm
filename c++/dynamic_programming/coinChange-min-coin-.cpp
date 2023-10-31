#include <iostream>
using namespace std;

int min(int a, int b) { return (a < b) ? a : b; }

int coinChange(int coinLen, int amount, int coins[])
{

    int coinTable[coinLen + 1][amount + 1];

    for (int i = 0; i <= coinLen; i++)
    {
        for (int j = 0; j <= amount; j++)
        {

            if (i == 0)
            {
                coinTable[i][j] = INT16_MAX; // Initialize the first row with a large value
            }
            else if (j == 0)
            {
                coinTable[i][j] = 0; // Initialize the first column with 0
            }
            else if (coins[i - 1] > j)
            {
                coinTable[i][j] = coinTable[i - 1][j];
            }
            else
            {
                coinTable[i][j] = min(coinTable[i - 1][j], 1 + coinTable[i][j - coins[i - 1]]);
            }
        }
    }

    return coinTable[coinLen][amount];
}

int main()
{

    int coins[] = {1, 5, 7, 9};
    int amount = 12;

    int n = sizeof(coins) / sizeof(coins[0]);

    cout << "Min number of coins = " << coinChange(n, 12, coins);

    return 0;
}
