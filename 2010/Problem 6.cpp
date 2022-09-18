#include "traffic.h"
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
const int MM = 1e6;
vector<int> adj[MM];
int total = 0, children[MM], fans[MM], mx[MM];
void dfs(int u, int prev) {
    for (auto &v : adj[u]) {
        if (v == prev) continue;
        dfs(v, u);
        children[u] += children[v];
        mx[u] = max(mx[u], children[v]);
    }
    mx[u] = max(mx[u], total - children[u] - fans[u]);
    children[u] += fans[u];
}
int LocateCentre (int N, int P[], int D[], int S[]) {
    int ans = INT_MAX, idx;
    for (int i = 0; i < N; i++) {
        total += P[i];
        fans[i] = P[i];
    }
    for (int i = 0; i < N-1; i++) {
        adj[D[i]].push_back(S[i]);
        adj[S[i]].push_back(D[i]);
    }
    dfs(0, -1);
    for (int i = 0; i < N; i++) {
        if (mx[i] < ans) {
            ans = mx[i];
            idx = i;
        }
    }
    return idx;
}
