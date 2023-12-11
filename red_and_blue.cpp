#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+5;

vector <int> adj[N];
int n;
bool flag = 1;
int cnt = 0;
int color[N], f[N];

void dfs (int x, int fa) {
    int son = 0;
    for (auto i : adj[x]) {
        if (i == fa)
            continue;
        dfs(i, x);
        son++;
    }
    if (son == 0 ||(!f[x])) {
        if (f[fa] || fa == 0) {
            flag = 0;
            return;
        }
        f[x] = f[fa] = ++cnt;
    }
}

void DFS (int x, int fa, int col) {
    color[x] = col;
    for (auto i : adj[x]) {
        if (i == fa)
            continue;
        if (f[i] == f[x])
            DFS(i, x, col);
        else
            DFS(i, x, 1-col);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf ("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    if (!flag) {
        cout << "-1" << endl;
        return 0;
    }
    DFS(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        if (color[i] == 1)
            cout << "R";
        else
            cout << "B";
    }
    return 0;
}
