#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vt vector
#define pb push_back
#define popf pop_front
#define popb pop_back
#define mp make_pair
#define umap unordered_map
#define fill memset

void solve() {
    int n, m, car, idx = 1, first;
    int sum = 0;
    cin >> n >> m;
    int rates[n+1], weights[m+1], available[n+1], position[m+1];
    queue<int> line;
    for (int i = 1; i <= n; i++) {
        cin >> rates[i];
        available[i] = true;
        position[i] = 0;
    }
    for (int i = 1; i <= m; i++) cin >> weights[i];
    for (int i = 1; i <= m*2; i++) {
        cin >> car;
        if (car > 0) {
            if (idx > n) line.push(car);
            else {
                sum += (weights[car] * rates[idx]);
                available[idx] = false;
                position[car] = idx;
                for (int j = idx; j <= n; j++) {
                    if (available[j]) {
                        idx = j;
                        break;
                    }
                    ++idx;
                }
            }
        } else {
            car = -car;
            available[position[car]] = true;
            idx = min(idx, position[car]);
            position[car] = 0;
            if (!line.empty()) {
                first = line.front();
                line.pop();
                sum += (weights[first] * rates[idx]);
                available[idx] = false;
                position[first] = idx;
                for (int j = idx; j <= n; j++) {
                    if (available[j]) {
                        idx = j;
                        break;
                    }
                    ++idx;
                }
            }
        }
    }
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TEST_CASES = 1;
    while (TEST_CASES --> 0) solve();
}
