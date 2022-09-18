#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
void play() {
    vector<int> track[25];
    for (int i = 1; i <= 50; i++) {
        track[faceup(i) - 'A'].push_back(i);
    }
    for (int i = 0; i < 25; i++) {
        faceup(track[i][0]);
        faceup(track[i][1]);
    }
}
