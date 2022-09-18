#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
void Solve() {
    int curTheory[4] = {-1, 6, 10, 6}, idx = -1;
    while (idx) {
        idx = Theory(curTheory[1], curTheory[2], curTheory[3]);
        if (!idx) break;
        curTheory[idx]--;
    }
    return;
}
