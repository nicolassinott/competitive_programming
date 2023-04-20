#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,m; cin >> n >> m;

    vector<ll> entry(n);
    ll exit_time;

    unordered_map<ll,ll> counter;
    // unordered_map<ll,ll> last_exit;

    for(ll i = 0; i < n; i++) cin >> entry[i];
    for(ll i = 0; i < m; i++) {
        cin >> exit_time;
        for(ll j = 0; j < n; j++){
            if(entry[j] > exit_time) break;
            ll time_diff = exit_time - entry[j];
            counter[time_diff]++;
        }
    }

    ll best_time = -1, best_frequency = -1;

    for(auto const [time,frequency] : counter){
        // cout << time << ' ' << frequency << endl;
        if(frequency >= best_frequency){
            if(frequency == best_frequency) {
                best_time = min(time, best_time);
            } else {
                best_time = time;
                best_frequency = frequency;
            }
        }
    }

    if(counter.empty()){
        cout << 0 << endl;
    } else {
        cout << best_time << endl;
    }


    return 0;
}