#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int numDoor;
    cin >> numDoor;
    vector<int> cowsNeeded;
    for (int i = 0; i < numDoor; ++i) {
        int n;
        cin >> n;
        cowsNeeded.emplace_back(n);
    }

    int minDistance = INT_MAX;
    for (int startPos = 0; startPos < numDoor; ++startPos) {
        int distance = 0;
        for (int step = 1; step < numDoor; ++step) {
            distance += cowsNeeded[(startPos + step) % numDoor] * step;
        }
        minDistance = min(minDistance, distance);
    }

    cout << minDistance;

    return 0;
}
