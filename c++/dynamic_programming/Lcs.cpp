#include <iostream>
#include <cstring>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int Lcs(char a[], char b[], int m, int n)
{

    int lcsTable[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0 || j == 0)
            {
                lcsTable[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1])
            {
                lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
            }
            else
            {

                lcsTable[i][j] = max(lcsTable[i - 1][j], lcsTable[i][j - 1]);
            }
        }
    }
    return lcsTable[m][n];
}

int main()
{

    char S1[] = "AGGTAB";
    char S2[] = "GXTXAYB";
    int m = strlen(S1);
    int n = strlen(S2);

    cout << "lcs = " << Lcs(S1, S2, m, n) << endl;

    // ans will be 4

    return 0;
}