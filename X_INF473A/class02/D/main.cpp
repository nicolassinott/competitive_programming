#include <bits/stdc++.h>
typedef long long ll;

int main(){
    ll t; std::cin >> t;
    
    while(t--){
        int n; std::cin >> n;
        std::unordered_set<ll> memory_allocations;
        std::vector<std::unordered_set<ll>> task_mp(n);
        
        for(ll i = 0; i < n; i++){
            ll memory; std::cin >> memory;
            task_mp[i].insert(memory);
            memory_allocations.insert(memory);

        }
        
        while(n--){
            
        }

    }

    return 0;
}

