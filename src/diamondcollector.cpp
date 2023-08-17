#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int numD, maxDiff;
    cin >> numD >> maxDiff;
    vector<int> d;
    for (int i = 0; i < numD; ++i) {
        int size;
        cin >> size;
        d.emplace_back(size);
    }
    sort(d.begin(), d.end());

    int maxNumD = 0;
    for (int i = 0; i < numD; ++i) {
        int compareTo = d[i];
        int currNum = 0;
        for (int j = i; j < numD; ++j) {
            if (d[j] - compareTo > maxDiff) {
                break;
            }
            ++currNum;
        }
        maxNumD = max(maxNumD, currNum);
    }

    cout << maxNumD;

    return 0;
}
