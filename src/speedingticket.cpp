#include <bits/stdc++.h>

using namespace std;

struct Speed {
    int pos;
    int speed;

    Speed(int pos, int speed) : pos(pos), speed(speed) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int numLimits, numBessie;
    cin >> numLimits >> numBessie;
    set<int> landmarks;
    landmarks.emplace(0);
    vector<Speed> limit;
    int pos = 0;
    for (int i = 0; i < numLimits; ++i) {
        int len, lim;
        cin >> len >> lim;
        pos += len;
        limit.emplace_back(pos, lim);
        landmarks.emplace(pos);
    }
    vector<Speed> bessie;
    pos = 0;
    for (int i = 0; i < numBessie; ++i) {
        int len, speed;
        cin >> len >> speed;
        pos += len;
        bessie.emplace_back(pos, speed);
        landmarks.emplace(pos);
    }

    int maxOver = 0;
    int bessieIdx = 0;
    int limitIdx = 0;
    for (const auto landmark: landmarks) {
        if (landmark > bessie[bessieIdx].pos) ++bessieIdx;
        if (landmark > limit[limitIdx].pos) ++limitIdx;
        maxOver = max(maxOver, bessie[bessieIdx].speed - limit[limitIdx].speed);
    }

    cout << maxOver;

    return 0;
}
