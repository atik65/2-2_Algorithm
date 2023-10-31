#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// const int N = 1e5 + 10;
const int N = 500000;

vector<int> g[N];
bool vis[N];

void dfs(int source)
{

    if (vis[source])
    {
        return;
    }

    cout << source << " ";
    vis[source] = true;

    for (int child : g[source])
    {

        dfs(child);
    }
}

int main()
{
    int n, m;
    cout << "Enter no. of vertex and edges: " << endl;
    cin >> n >> m;

    cout << "Enter adjacent nodes: " << endl;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << "Output after dfs: " << endl;

    dfs(0);
}