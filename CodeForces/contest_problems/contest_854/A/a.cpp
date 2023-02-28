#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll t; cin >> t;

    for(ll j = 0; j < t; j++){
        ll n; ll m; cin >> n >> m;
        ll counter = 1;
        vector<ll> output(n);
        vector<ll> seen(m);
        ll new_element;

        for(ll i = 0; i < m; i++){
            seen[i] = 0;
        }

        for(ll i = 0; i < n; i++){
            output[i] = -1; 
        }

        for(ll i = 0; i < m; i++){
            cin >> new_element;
            if(output[0] != -1) continue;
            new_element = new_element - n - 1;

            if(!seen[new_element]){
                seen[new_element] = 1;
                output[n - counter] = i + 1;
                seen[new_element] = 1;
                counter++;
            }
        }

        for(ll i = 0; i < n; i++){
            cout << output[i] << ' ';
        }

        cout << endl;
    } 
    return 0;
}