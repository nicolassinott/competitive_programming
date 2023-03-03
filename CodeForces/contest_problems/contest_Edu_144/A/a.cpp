#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

bool is_substring(vector<char>& s, vector<char>& sequence){
    bool is_sub = 1;

    for(int i = 0; i < s.size(); i++){
        if(s[i] != sequence[(i%8)]){
            is_sub = 0;
            break;
        }
    }
    
    return is_sub;
}

bool solve(vector<char>& s, vector<vector<char>>& sequences){

    bool is_sub = 0;

    for(int i = 0; i < 8; i++){
        is_sub = is_sub || is_substring(s,sequences[i]);
    }

    return is_sub;
}

int main(){

    int t; cin >> t;

    vector<vector<char>> sequences;
    sequences.push_back({'F', 'B', 'F', 'F', 'B', 'F', 'F', 'B'});

    for(int i = 1; i < 8; i++){
        vector<char> new_sequence;
        for(int j = 0; j < 8; j++){
            new_sequence.push_back(sequences[0][((i+j)%8)]);
        }
        sequences.push_back(new_sequence);
    }

    while(t--){
        int si; cin >> si;
        char curr_char;
        vector<char> s;
        for(int i = 0; i < si; i++){
            cin >> curr_char;
            s.push_back(curr_char);
        }
        if(solve(s, sequences)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}