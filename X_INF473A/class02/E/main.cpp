#include <bits/stdc++.h>
typedef long long ll;

// ll compute_in_substring(std::string& st, ll n_ones, ll index_start, ll & mod_number, ll n_inversions){

//     for(ll i = index_start; i < st.size(); i++){
//         if(st[i] == '0') {
//             n_inversions += n_ones;
//             n_inversions %= mod_number;
//         } else if (st[i] == '1') {
//             n_ones++;
//         } else {
//             return (compute_in_substring(st, n_ones + 1, i+1, mod_number, n_inversions) + compute_in_substring(st, n_ones, i+1, mod_number, n_inversions)) % mod_number;
//         }
//     }
//     return n_inversions % mod_number;
// }

int main(){
    std::string st; std::cin >> st;
    ll mod_number = 1000000007;
    ll n_ones = 0; 
    ll n_inversions = 0;
    // std::cout << compute_in_substring(st, n_ones, 0, mod_number, n_inversions) << std::endl;
    // n_inversions = compute_in_substring(st, n_ones, 0, mod_number, n_inversions);    
    // std::cout << compute_in_substring(st, n_ones, 0, mod_number) % mod_number << std::endl;

    

    for(ll i = 0; i < st.size(); i++){
        if(st[i] == '0') {
            n_inversions += n_ones;
            n_inversions %= mod_number;
        } else if (st[i] == '1') {
            n_ones++;
        } else {
            n_inversions = (2 * n_inversions) % mod_number;
            n_inversions = (n_inversions + n_ones) % mod_number; 
            n_inversions %= mod_number;
            
            n_ones = (2 * n_ones + 1) % mod_number;
        }
    }

    std::cout << n_inversions % mod_number << std::endl;

    return 0;
}

