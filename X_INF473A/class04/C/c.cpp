#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m; cin >> n >> m;
    
    while(1){
        priority_queue<vector<ll>> cities;
        
        for(int i = 0; i < n; i++) {
            ll temp; cin >> temp;
            cities.push({temp, 1, temp});
        } 

        m -= n;

        while(m--){
            vector<ll> highest_population = cities.top(); cities.pop();
            highest_population[1]++;
            highest_population[0] = (highest_population[2] + highest_population[1] - 1) / highest_population[1];
            cities.push(highest_population);
        }

        cout << cities.top()[0] << endl;

        cin >> n >> m;
        if(n == -1 && m == -1) break;
    }

    return 0;
}