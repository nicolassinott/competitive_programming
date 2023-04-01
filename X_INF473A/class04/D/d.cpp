#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k; cin >> n >> k;
    vector<pair<ll,ll>> activities;
    
    for(int i = 0; i < n; i++) {
        ll temp1, temp2; cin >> temp1 >> temp2;
        activities.push_back({temp2,temp1});
    }

    sort(activities.begin(), activities.end());

    multiset<ll> rolling_activities;
    for(ll i = 0; i < k; i++) rolling_activities.insert(0);

    ll counter = 0;
    set<ll>::iterator it;

    for(int i = 0; i < n; i++){
        auto [end_time, start_time] = activities[i];
        it = rolling_activities.lower_bound(start_time); 
        
        if(it == rolling_activities.begin()) continue;
        
        it--;
        rolling_activities.erase(it);  
        counter++;
        rolling_activities.insert(end_time);
    }

    cout << counter << endl;

    return 0;
}