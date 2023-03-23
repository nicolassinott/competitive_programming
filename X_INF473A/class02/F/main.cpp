#include <bits/stdc++.h>
typedef long long ll;

void solve(ll n){
    ll curr_element = 0;
    std::vector<ll> position_map(n);

    for(ll i = 0; i < n; i++){
        std::cin >> curr_element;
        position_map[curr_element] = i;
    }

    for(ll i = 0; i < n; i++){
        for(ll diff = -n / 3 - 1; diff < n/3 + 1; diff++){
            if(i + 2*diff >=0 && i + 2*diff < n){
                if(position_map[i] < position_map[i + diff] && position_map[i + diff] < position_map[i + 2*diff]){
                    std::cout << "no" << std::endl; return;
                }
            }
        }
    }

    std::cout << "yes" << std::endl;
}

int main(){
    std::string nstring; std::cin >> nstring;
    while(1){
        ll n = nstring[0] - '0'; if(!n) break;
        solve(n);
        std::cin >> nstring;        
    }
    return 0;
}
