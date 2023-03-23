#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

int main(){
    ll n; std::cin >> n;
    std::unordered_map<std::string, std::vector<ll>> countries_mp;

    std::unordered_set<std::string> sorted_set; 

    std::string s; ll y;
    while(n--){
        std::cin >> s >> y;
        if(countries_mp.size()) countries_mp[s].push_back(y);
        else countries_mp[s] = {y};
    }

    ll n_queries; std:: cin >> n_queries;
    ll k;

    while(n_queries--){
        std::cin >> s >> k;
        if(sorted_set.count(s)) {
            std::cout << countries_mp[s][k - 1] << std::endl;
        } else {
            std::sort(countries_mp[s].begin(), countries_mp[s].end());
            std::cout << countries_mp[s][k - 1] << std::endl;
            sorted_set.insert(s);
        }  
    }

    return 0;
}