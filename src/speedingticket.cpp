#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen("speeding.in", "r", stdin);
//    freopen("speeding.out", "w", stdout);

    int numLimits, numBessie;
    cin >> numLimits >> numBessie;
    vector<pair<int, int>> limit;
    vector<pair<int, int>> bessie;
    set<int> landmarks;
    int limLen = 0;
    for (int i = 0; i < numLimits; ++i) {
        int len, lim;
        cin >> len >> lim;
        pair<int, int> temp = {len, lim};
        limit.emplace_back(temp);
        limLen += len;
        landmarks.emplace(limLen);
    }
    int bessieLen = 0;
    for (int i = 0; i < numBessie; ++i) {
        int len, speed;
        cin >> len >> speed;
        pair<int, int> temp = {len, speed};
        bessie.emplace_back(temp);
        bessieLen += len;
        landmarks.emplace(bessieLen);
    }

    int maxOver = 0;
    int limIdx = 0;
    int bessieIdx = 0;
    for (int landmark: landmarks) {

    }

    cout << maxOver;

    return 0;
}
