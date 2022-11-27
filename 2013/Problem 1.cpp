#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5;
vector<pair<int, int>> adj[MM];
int len = 0, maxRadius = 0, bestCenter = 0;
bool vis[MM];
vector<int> centers;

void dfs(int u, int parent, int d, int &endpoint, unordered_set<int> &track) {
    vis[u] = true;
    track.insert(u);
    if (d >= len) {
        len = d;
        endpoint = u;
    }
    for (auto [v, w] : adj[u]) {
        if (v == parent) continue;
        dfs(v, u, d + w, endpoint, track);
    }
}

void dfs2(int u, int parent, int d, int (&dis)[MM]) {
    dis[u] = max(dis[u], d);
    for (auto [v, w] : adj[u]) {
        if (v == parent) continue;
        dfs2(v, u, d + w, dis);
    }
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    for (int i = 0; i < M; i++) {
        adj[A[i]].emplace_back(B[i], T[i]);
        adj[B[i]].emplace_back(A[i], T[i]);
    }
    for (int i = 0; i < N; i++) {
        if (!vis[i] && !adj[i].empty()) {
            unordered_set<int> nodes;
            int dis[MM] = {0}, endA = 0, endB = 0, radius = INT_MAX, center = 0;
            len = 0;
            dfs(i, -1, 0, endA, nodes);
            dfs(endA, -1, 0, endB, nodes);
            dfs2(endA, -1, 0, dis);
            dfs2(endB, -1, 0, dis);
            for (int u : nodes) {
                if (dis[u] < radius) {
                    radius = dis[u];
                    center = u;
                }
            }
            centers.push_back(center);
            if (radius >= maxRadius) {
                maxRadius = radius;
                bestCenter = center;
            }
        }
    }
    for (int u : centers) {
        if (u == bestCenter) continue;
        adj[bestCenter].emplace_back(u, L);
        adj[u].emplace_back(bestCenter, L);
    }
    for (int i = 0; i < N; i++) {
        if (!vis[i] && i != bestCenter) {
            adj[bestCenter].emplace_back(i, L);
            adj[i].emplace_back(bestCenter, L);
        }
    }
    unordered_set<int> nodes;
    int endA = 0, endB = 0;
    len = 0;
    dfs(bestCenter, -1, 0, endA, nodes);
    dfs(endA, -1, 0, endB, nodes);
    return len;
}
