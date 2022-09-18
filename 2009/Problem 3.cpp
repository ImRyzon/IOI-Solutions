#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vt vector
#define pb push_back
#define emp emplace
#define popf pop_front
#define popb pop_back
#define mp make_pair
#define umap unordered_map
#define fill memset

const int MM = 2001;
int points[MM], scores[MM], numSolved[MM], id[MM];
bool solved[MM][MM];

void solve() {
    int n, t, p, task;
    cin >> n >> t >> p;
    int tracker = p;
    for (int i = 1; i <= n; i++) {
        scores[i] = 0;
        numSolved[i] = 0;
        id[i] = i;
        for (int j = 1; j <= t; j++) {
            cin >> task;
            solved[i][j] = task == 1;
            if (task == 1) ++numSolved[i];
            else ++points[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            if (solved[i][j]) scores[i] += points[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i; j++) {
            if (scores[j] > scores[j+1]) continue;
            if (scores[j] < scores[j+1] || numSolved[j] < numSolved[j+1] || id[j] > id[j+1]) {
                int tempScore = scores[j], tempSolved = numSolved[j], tempId = id[j];
                scores[j] = scores[j+1];
                numSolved[j] = numSolved[j+1];
                id[j] = id[j+1];
                scores[j+1] = tempScore;
                numSolved[j+1] = tempSolved;
                id[j+1] = tempId;
                tracker = id[j] == p ? j : id[j+1] == p ? j + 1 : tracker;
            }
        }
    }
    cout << scores[tracker] << " " << tracker << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TEST_CASES = 1;
    while (TEST_CASES --> 0) solve();
}
