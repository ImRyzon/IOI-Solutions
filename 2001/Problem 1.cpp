#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
const int MM = 1025;
int BIT[MM][MM], S, op;
void update(int r, int c, int x) {
    for (int i = r; i <= S; i += i & -i) {
        for (int j = c; j <= S; j += j & -j) {
            BIT[i][j] += x;
        }
    }
}
int query(int r, int c) {
    int sum = 0;
    for (int i = r; i; i -= i & -i) {
        for (int j = c; j; j -= j & -j) {
            sum += BIT[i][j];
        }
    }
    return sum;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> op >> S >> op;
    while (op != 3) {
        if (op == 1) {
            int x, y, a;
            cin >> x >> y >> a;
            ++x; ++y;
            update(x, y, a);
        } else {
            int l, b, r, t;
            cin >> l >> b >> r >> t;
            ++l; ++b; ++r; ++t;
            cout << query(r, t) - query(l-1, t) - query(r, b-1) + query(l-1, b-1) << '\n';
        }
        cin >> op;
    }
}
