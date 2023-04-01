#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, r, c; cin >> n >> r >> c;

    vector<pair<ll,ll>> preferences(n);

    vector<ll> available_seats(r, c);

    for(ll i = 0; i < n; i++){
        ll row, col, s; cin >> row >> col >> s;
        row--; col--;
        preferences[i] = {max((ll) 0, row - s), min((ll) r - 1, row + s)};
    }

    sort(preferences.begin(), preferences.end());

    ll counter = 0;
    ll curr_preference = 0;

    priority_queue<ll, vector<ll>, greater<ll>> pq_end_first;

    for(ll curr_row = 0; curr_row < r; curr_row++){
        
        while(curr_preference < n && preferences[curr_preference].first <= curr_row){
            pq_end_first.push(preferences[curr_preference].second);
            curr_preference++;
        }

        while(available_seats[curr_row] && !pq_end_first.empty()){
            ll end_row = pq_end_first.top(); pq_end_first.pop();
            if(end_row >= curr_row){
                available_seats[curr_row]--;
                counter++;
            }
        }
    }

    cout << counter << endl;

    return 0;
}