#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    string curr_word;
    vector<char> word_count(26);

    while(t--){
        cin >> curr_word;

        for(char ch : curr_word){
            word_count[ch - 'a']++;
        }

    }
}