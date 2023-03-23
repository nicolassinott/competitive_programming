#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; 
    while(1){
        cin >> n;
        if(!n) break;

        ll height;
        vector<pair<ll,ll>> extendable;
        ll max_area = 0;
        ll x_old;

        for(ll i = 0; i < n; i++){
            cin >> height;

            if(extendable.empty()){
                extendable.push_back({i,height});
                continue;
            }

            auto[x,y] = extendable.back();

            if(y < height){
                extendable.push_back({i,height});
                continue;
            }

            if(y == height) continue;

            x_old = i;

            while(!extendable.empty()){
                auto[x,y] = extendable.back();
                
                if(y < height){
                    extendable.push_back({x_old, height});
                    break;
                } 
                
                extendable.pop_back();
                max_area = max(max_area, (i - x) * y);

                x_old = x;
            }

            if(extendable.empty()){
                extendable.push_back({0, height});
            }

        }

        while(!extendable.empty()){
            auto[x,y] = extendable.back();
            extendable.pop_back();
            max_area = max(max_area, (n - x) * y);
        }

        cout << max_area << endl;
    }

    return 0;

}