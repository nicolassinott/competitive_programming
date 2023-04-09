#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t; cin >> t;

    while(t--){
        ll n; cin >> n;
        ll el;

        if(n%2){
            for(ll i = 0; i < n; i++) 
                cin >> el;
            cout << "YES" << endl;
        } else {
            ll credit = 0;
            ll first_el; cin >> first_el;

            for(ll i = 1; i < n; i++){
                cin >> el;
                el += credit;
                credit = first_el - el;
            }

            if(credit > 0){
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
        
    }

    return 0;
}