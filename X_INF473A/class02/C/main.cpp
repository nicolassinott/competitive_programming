#include <bits/stdc++.h>
typedef long long ll;

int main(){
    ll m; std::cin >> m;

    std::string person; std::string word;
    std::unordered_set<std::string> word_list;
    std::unordered_set<std::string> person_list; ll n_persons = 0;
    std::unordered_map<std::string, std::unordered_set<std::string>> person_mp;
    std::vector<std::pair<ll, std::string>> answer;
    std::unordered_map<std::string, ll> word_frequency;

    while(m--){
        std::cin >> person;
        if(!person_list.count(person)){
                person_list.insert(person);
                n_persons++;
            }
        
        std::string words;
        std::getline(std::cin, words);
        std::stringstream ss(words);

        while(ss >> word) {
            word_list.insert(word);
            person_mp[person].insert(word);
            if(word_frequency.count(word)){
                word_frequency[word]--;
            } else {
                word_frequency[word] = -1;
            }
        }
    }

    for (std::string word : word_list){
        ll counter = 0;
        for(std::string person : person_list){
            if(!person_mp[person].count(word)) break;
            counter++;
        }
        if(n_persons == counter) answer.push_back({word_frequency[word], word});
    }

    std::sort(answer.begin(), answer.end());

    if(answer.empty()) std::cout << "ALL CLEAR" << std::endl;
    
    else for(int i = 0; i < answer.size(); i++) std::cout << answer[i].second << std::endl;

    return 0;
}