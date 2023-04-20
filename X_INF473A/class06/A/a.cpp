#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll w, n; cin >> w >> n;

    ll surface = 0;
    ll a, b;


    for(ll i = 0; i < n; i++){
        cin >> a >> b;
        surface += a*b;
    }

    cout << surface/w << endl;


    return 0;
}