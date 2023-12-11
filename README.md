# CMSC398L Final Presentation

## Problem: Red and Blue

This is a problem written in Chinese, so I translated it as below.

### Problem Description

You have been given a tree and have been asked to color each vertex red or blue.

Requirements: Each red point is surrounded by one and only one red point and each blue point is surrounded by one and only one blue point.

Definition of "around": Points around a point are points that are directly connected by neighboring edges.

### Input Description

The first line is a positive integer $n$, representing the number of vertices of the tree ($1 \le n \le 100000$).

The following $n-1$ lines have two positive integers $u$ and $v$ each line, representing the point $u$ and the point $v$ are connected by an edge ($1 \le u, v \le n$).

It is guaranteed that the input must be a legal tree.

### Output Description

If the coloring requirement can be reached, output a string with length $n$. The first $i$ character represents the coloring of the $i$-th vertex, with $'B'$ as blue, and $'R'$ as red. (If there are multiple legal coloring methods, output any one of them.) 

Otherwise, output $-1$ directly.

### Example

#### Input

```
4
1 2
2 3
3 4
```

#### Output

```
RRBB
```

## Analysis

## Solution

```c++
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
```
