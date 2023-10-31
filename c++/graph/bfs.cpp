#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// const int N = 1e5 + 10;
const int N = 500000;

vector<int> g[N];
int vis[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;

    while (!q.empty())
    {

        int cur_vertex = q.front();
        q.pop();
        cout << cur_vertex << " ";

        for (int child : g[cur_vertex])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
            }
        }
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

    cout << "Output after bfs: " << endl;

    bfs(0);
}