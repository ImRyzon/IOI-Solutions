#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define scan(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int N, ans = INT_MAX, idx;
    scan(N);
    for (int i = 0; i < N; i++) {
        scan(fans[i]);
        total += fans[i];
    }
    for (int i = 0, u, v; i < N-1; i++) {
        scan(u);
        scan(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    for (int i = 0; i < N; i++) {
        if (mx[i] < ans) {
            ans = mx[i];
            idx = i;
        }
    }
    printf("%d\n", idx);
}
