#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<ll> lengths(3,0);
    ll n; cin >> n;

    ll new_length;

    for(ll i = 1; i <= n; i++){
        cin >> new_length;
        lengths[i%3] += new_length;
    }

    vector<ll> areas(3,0);

    for(ll j = 1; j <= n; j++){
        cin >> new_length;
        for(int i = 0; i < 3; i++){
            areas[(i+j)%3] += new_length * lengths[i]; 
        }
    }

    for(int i = 0; i < 3; i++){
        cout << areas[i] << ' ';
    }
    cout << endl;

    return 0;
}