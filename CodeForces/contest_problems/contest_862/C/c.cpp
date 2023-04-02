#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        vector<ll> angular_coef(n);

        for(int i=0; i<n; i++) cin >> angular_coef[i];
        sort(angular_coef.begin(), angular_coef.end());

        for(int i = 0; i < m; i++){
            ll a,b,c; cin >> a >> b >> c;

            if(c <= 0) {
                cout << "NO" << endl;
                continue;
            }

            // cout << "Product ac " << a * c << endl;
            // cout << a << " " << c << endl;

            double smallest_k = b - 2 * (double) sqrt((double) a * c);
            double largest_k = b + 2 * (double) sqrt((double) a * c);

            // cout << "smallest et largest" << smallest_k << " " << largest_k << endl;

            vector<ll>::iterator it = upper_bound(angular_coef.begin(), angular_coef.end(), smallest_k);
            if(it == angular_coef.end()) cout << "NO" << endl;
            else {
                if(*it > smallest_k && *it < largest_k){
                    cout << "YES" << endl;
                    cout << *it << endl;
                } else {
                    cout << "NO" << endl;
                }
                // it--;
                // if(*it > smallest_k && *it < largest_k) { 
                //     cout << "YES" << endl;
                //     cout << *it << endl;
                // } else {
                //     cout << "NO" << endl;
                // }
            }
        }
    }




    return 0;
}