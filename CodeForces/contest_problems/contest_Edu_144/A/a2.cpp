#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// bool is_substring(vector<char>& s, vector<char>& sequence){
//     bool is_sub = 1;

//     for(int i = 0; i < s.size(); i++){
//         if(s[i] != sequence[(i%8)]){
//             is_sub = 0;
//             break;
//         }
//     }
    
//     return is_sub;
// }

// void solve(vector<char>& s, vector<vector<char>>& sequences){

//     bool is_sub = 0;

//     for(int i = 0; i < 8; i++){
//         is_sub = is_sub || is_substring(s,sequences[i]);
//     }

//     if(is_sub) cout << "YES" << endl;
//     else cout << "NO" << endl;
// }

int main(){

    int t; cin >> t;

    vector<vector<char>> sequences(8);
    sequences[0] = {'F', 'B', 'F', 'F', 'B', 'F', 'F', 'B'};

    for(int i = 1; i < 8; i++){
        vector<char> new_sequence(8);
        for(int j = 0; j < 8; j++){
            new_sequence[j] = sequences[0][((i+j)%8)];
        }
        sequences[i] = new_sequence;
    }

    while(t--){
        int si; cin >> si;
        vector<char> s(si);
        for(int i = 0; i < si; i++){
            cin >> s[i];
        }
        
        bool is_sub = 0;

        for(int i = 0; i < 8; i++){
            bool is_sub2 = 1;
            for(int j = 0; j < s.size(); j++){
                if(s[j] != sequences[i][(j%8)]){
                    is_sub2 = 0;
                    break;
                }
            }

            is_sub = is_sub || is_sub2;
            if(is_sub) break;
        }

        if(is_sub) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 1;
}