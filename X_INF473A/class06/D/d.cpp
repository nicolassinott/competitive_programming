#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t; cin >> t;
    ll n_cases = pow(2,20);
    vector<ll> elements(20);
    ll sol_1 = 4, sol_2 = 7;

    ll N;
    
    for(ll cas = 1; cas <= t; cas++){
        vector<ll> forward_map(n_cases,0);
        unordered_map<ll,ll> backward_map;

        cin >> N;

        ll curr_entry = 1;
        ll new_curr_entry = 1;

        bool found_solution = 0;

        // generating all maps
        for(ll i = 0; i < N; i++){
            cin >> elements[i];
            if(found_solution) continue;
            for(ll j = 0; j < curr_entry; j++){
                ll soma = forward_map[j] + elements[i];
                forward_map[new_curr_entry] = soma;
                
                if(backward_map[soma] != 0){
                    // found the solution
                    sol_1 = backward_map[soma];
                    sol_2 = new_curr_entry;
                    found_solution = 1; 
                } else {
                    backward_map[soma] = new_curr_entry;
                    new_curr_entry++;
                }
            }
            curr_entry = new_curr_entry;
        }

        // find the disjoint sets

        if(!found_solution) {
            cout << "impossible" << endl;
            continue;
        }

        // printing out solutions where
        // sol1 and sol2 are the two sets

        ll sum_1 = 0;
        ll sum_2 = 0;

        cout << "Case #" << cas << ':' << endl;
        for(int i = 0; i < N; i++){
            if(1 & (sol_1 >> i)){
                cout << elements[i] << ' ';
                sum_1 += elements[i];
            }
        }
        cout << "sum " << sum_1 << endl;
        cout << endl;
        for(int i = 0; i < N; i++){
            if(1 & (sol_2 >> i)){
                cout << elements[i] << ' ';
                sum_2 += elements[i];
            }
        }
        cout << "sum " << sum_2 << endl;
        cout << endl;

    }

    return 0;
}