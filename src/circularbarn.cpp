#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen("cbarn.in", "r", stdin);
//    freopen("cbarn.out", "w", stdout);

    int numDoor;
    cin >> numDoor;
    vector<int> cowsNeeded;
    for (int i = 0; i < numDoor; ++i) {
        int n;
        cin >> n;
        cowsNeeded.emplace_back(n);
    }

    int minDistance = INT_MAX;
    for (int i = 0; i < numDoor; ++i) {
        int idx = i + 1;
        int distance = 0;
        for (int j = 1; j < numDoor; ++j) {
            distance += cowsNeeded[idx] * j;
            ++idx;
            idx %= numDoor;
        }
        minDistance = min(minDistance, distance);
    }

    cout << minDistance;

    return 0;
}
