#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;

    while(t--){
        ll n, k; cin >> n >> k;
        vector<pair<ll,ll>> intervals(n);
        // ll first_count = 0;
        // bool possible = 0;

        for(ll i = 0; i < n; i++){
            cin >> intervals[i].first;
        }

        for(ll i = 0; i < n; i++){
            cin >> intervals[i].second;
            intervals[i].second *= -1;  
        }

        

        sort(intervals.begin(), intervals.end());

        for(ll i =0; i < n; i++){
            intervals[i].second *= -1;
        }

        // for(int i = 0; i < n; i++){
        //     cout << '{' << intervals[i].first << ',' << intervals[i].second << "}, ";
        // }
        // cout << endl;

        ll count = 0;
        ll possible_ones = 0; // may discard as not worth it sometimes

        // may need to be a list...

        ll crossing_left = 0;
        ll crossing_right = 0;

        ll colored_black = 0;

        ll i = 0;
        while(i < n){
            // cout << "initial i " << i << endl;
            crossing_left += 1;
            auto[l,r] = intervals[i];
            //get max interval possible
            ll j = i;
            while(j < n){
                j++;
                if(j == n) break;
                auto[lnext, rnext] = intervals[j];
                if(lnext > r+1) break;
                else r = max(r, rnext);
            } 
            i = j - 1;

            // cout << l << ' ' << r << endl;

            // cout << "currently "<< colored_black << endl;

            if(r - l + 1 + colored_black >= k){
                count = l + k - colored_black;
                colored_black = k;
                break;
                
            } else {
                colored_black += r-l+1;
                crossing_right += 1;
            }
            i++;
        }
        if(colored_black == k) {
            cout << count + crossing_left + crossing_right << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}