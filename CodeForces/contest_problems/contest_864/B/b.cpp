#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;

    while(t--){
        ll n, k; cin >> n >> k;
        vector<vector<bool>> table(n, vector<bool>(n,0));
        
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                bool a; cin >> a;
                table[i][j] = a;
            }
        }

        ll different_colors = 0;

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                different_colors += table[i][j] ^ table[n-1-i][n-1-j];
            }
        }

        different_colors /= 2;

        if(!(n%2)){
            if(k-different_colors >= 0 && !((k-different_colors) % 2)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else {
            if(k-different_colors >= 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }

    }

    return 0;
}