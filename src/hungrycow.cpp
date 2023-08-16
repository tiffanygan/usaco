#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int numDeliveries;
    ll numDays;
    cin >> numDeliveries >> numDays;
    vector<pair<ll, int>> deliveries;
    for (int i = 0; i < numDeliveries; ++i) {
        ll day;
        int amt;
        cin >> day >> amt;
        deliveries.emplace_back(day, amt);
    }

    // first delivery day
    ll numEaten = 1;
    ll numLeft = deliveries[0].second - 1;
    ll prevDeliveryDay = deliveries[0].first;
    ll currDeliveryDay;
    for (int i = 1; i < numDeliveries; ++i) {
        currDeliveryDay = deliveries[i].first;
        ll daysInBetween = currDeliveryDay - prevDeliveryDay - 1;
        if (numLeft > daysInBetween) {
            numEaten += daysInBetween;
            numLeft -= daysInBetween;
        } else {
            numEaten += numLeft;
            numLeft = 0;
        }
        numLeft += deliveries[i].second;
        ++numEaten;
        --numLeft;
        prevDeliveryDay = currDeliveryDay;
    }

    if (deliveries[numDeliveries - 1].first < numDays) {
        if (numLeft - (numDays - deliveries[numDeliveries - 1].first) > 0) {
            numEaten += numDays - deliveries[numDeliveries - 1].first;
        } else if (numLeft > 0) {
            numEaten += numLeft;
        }
    }

    cout << numEaten;

    return 0;
}
