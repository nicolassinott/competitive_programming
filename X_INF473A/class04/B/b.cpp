#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m; cin >> n >> m;
    vector<ll> fish_weights(n,0);
    vector<pair<ll,ll>> buyers(m,{0,0});

    for(ll i = 0; i < n; i++) cin >> fish_weights[i];
    for(ll i = 0; i < m; i++) cin >> buyers[i].second >> buyers[i].first;

    sort(fish_weights.begin(), fish_weights.end());
    sort(buyers.begin(), buyers.end());

    ll profit = 0;
    ll curr_buyer = m - 1;

    for(ll i = n - 1; i >= 0; i--){
        while (!buyers[curr_buyer].second) curr_buyer--;
        if (curr_buyer < 0) break;
        profit += buyers[curr_buyer].first * fish_weights[i];
        buyers[curr_buyer].second--;
    }

    cout << profit << endl;

    return 0;
}