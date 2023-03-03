#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_substring(string& s, vector<char>& sequence){
    bool is_sub = 0;

    for(int i = 0; i < sequence.size(); i++){
        if(s[i] != sequence[i%8]){
            is_sub = 0;
            break;
        }
    }
    
    return is_sub;
}

void solve(string& s, vector<vector<char>>& sequences){

    bool is_sub = 1;

    for(int i = 0; i < 8; i++){
        is_sub = is_sub ||is_substring(s,sequences[i]);
    }

    if(is_sub) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){

    ll t; cin >> t;

    vector<vector<char>> sequences;
    vector<char> sequence0 = {'F', 'B', 'F', 'F', 'B', 'F', 'F', 'B'};
    sequences.push_back(sequence0);

    for(int i = 1; i < 8; i++){
        vector<char> new_sequence(8);
        for(int j = 0; j < 8; j++){
            new_sequence[j] = sequence0[(i+j)%8];
        }
        sequences.push_back(new_sequence);
    }

    while(t--){
        string s; cin >> s;
        solve(s, sequences);
    }

    return 1;
}