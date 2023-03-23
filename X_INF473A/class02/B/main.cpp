#include <bits/stdc++.h>
typedef long long ll;

bool is_prime(ll n){
    for(ll i = 2; i <= std::sqrt(n); i++) if(n % i == 0) return 0;
    return 1;
}

ll solve(ll n){
    ll start = 2*n + 1;
    while(!is_prime(start)) start++;
    return start;
}

int main(){
    ll n;

    while(1){
        std::cin >> n; if(n == 0) break;
        if(is_prime(n)) std::cout << solve(n) << std::endl;
        else std::cout << solve(n) << " (" << n <<" is not prime)" << std::endl;
    }

    return 0;
}