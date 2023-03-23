#include <bits/stdc++.h>
typedef long long ll;

int main(){

    std::string nstring; std::cin >> nstring;

    while(1){
        int n = nstring[0] - '0'; if(!n) break;

        std::vector<int> permutation(n);
        std::unordered_set<int> seen;

        std::vector<int> previous_elements(n);
        bool found = 0;

        for(int i = 0; i < n; i++){
            std::cin >> previous_elements[i];
            if (found) continue;
            for(int j = 0; j < i; j++){
                int diff = previous_elements[i] - previous_elements[j];
                if(previous_elements[i] + diff < n && previous_elements[i] + diff >= 0 && !seen.count(previous_elements[i] + diff)) found = 1;
            }
            seen.insert(previous_elements[i]);
        }

        if(found) std::cout << "no" << std::endl;
        else std::cout << "yes" << std::endl;
        std::cin >> nstring;
    }


    return 0;
}
