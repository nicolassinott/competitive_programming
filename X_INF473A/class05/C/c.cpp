#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dp(vector<vector<ll>>& u, ll n, ll v){
    if(u[n][v] != -1) return;
    if(v == n-1){
        u[n][v] = 1;
        return;
    } 
    if(v == 0) {
        u[n][v] = 1;
        return; 
    }
    dp(u,n-1,v-1); dp(u,n-1,v);
    u[n][v] = ((n-v) * u[n-1][v-1] + (v+1) * u[n-1][v]) % 1001113;
}

int main() {
    ll t; cin >> t;
    ll index, n, v;

    for(int i = 0; i < t; i++){
        cin >> index >> n >> v;
        vector<vector<ll>> u(n+1, vector<ll>(v + 1,-1));
        dp(u, n, v);
        cout << index << " " << u[n][v] << endl;
    }

    return 0;
}