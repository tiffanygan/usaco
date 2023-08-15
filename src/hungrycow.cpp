#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int numDel;
    ll numDays;
    cin >> numDel >> numDays;
    set<ll> delDays;
    vector<pair<ll, int>> deliveries;
    for (int i = 0; i < numDel; ++i) {
        ll day;
        int amt;
        cin >> day >> amt;
        pair<ll, int> temp = {day, amt};
        deliveries.emplace_back(temp);
        delDays.emplace(day);
    }

    ll numEaten = 1;
    ll numLeft = deliveries[0].second - 1;
    for (int i = 1; i < numDel; ++i) {
        ll numDaysPassed = deliveries[i].first - deliveries[i - 1].first - 1;
        if (numLeft - numDaysPassed > 0) {
            numEaten += numDaysPassed;
            numLeft -= numDaysPassed;
        } else if (numLeft > 0) {
            numEaten += numLeft;
            numLeft = 0;
        }
        numLeft += deliveries[i].second;
        ++numEaten;
        --numLeft;
    }

    if (deliveries[numDel - 1].first < numDays) {
        if (numLeft - (numDays - deliveries[numDel - 1].first) > 0) {
            numEaten += numDays - deliveries[numDel - 1].first;
        } else if (numLeft > 0) {
            numEaten += numLeft;
        }
    }

    cout << numEaten;

    return 0;
}
