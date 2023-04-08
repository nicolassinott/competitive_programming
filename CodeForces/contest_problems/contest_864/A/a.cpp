#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;

    while(t--){
        ll n, m; cin >> n >> m;
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        int count1 = 0; int count2 = 0;

        if(x1 - 1 > 0) count1++;
        if(x1 + 1 <= n) count1++;
        if(y1 - 1 > 0) count1++;
        if(y1 + 1 <= m) count1++; 
        
        if(x2 - 1 > 0) count2++;
        if(x2 + 1 <= n) count2++;
        if(y2 - 1 > 0) count2++;
        if(y2 + 1 <= m) count2++;

        cout << min(count1, count2) << endl;
    }

    return 0;
}