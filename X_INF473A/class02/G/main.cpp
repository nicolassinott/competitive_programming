#include <bits/stdc++.h>
typedef long long ll;

int main(){
    int n, q;
    std::cin >> n >> q;

    std::vector<bool> primes(n+1);
    primes[0] = 1;
    primes[1] = 1;

    for(int i = 2; i <= std::sqrt(n); i++){
        if(primes[i] == 1) continue;
        for(int j = 2 * i; j <= n; j += i){
            primes[j] = 1;
        }
    }

    int counter = 0;

    for(int i = 0; i <= n; i++){
        counter += !primes[i];   
    }

    std::cout << counter << std::endl;

    while(q--){
        int number; std::cin >> number;
        std::cout << !primes[number] << std::endl;
    }

    return 0;
}