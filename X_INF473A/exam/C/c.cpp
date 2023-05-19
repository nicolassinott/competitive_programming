#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s; cin >> s;
    string s_inverted = s; reverse(s_inverted.begin(), s_inverted.end());

    int size_s = s.size();

    bool ok = 0;

    for(int i = 0; i < size_s; i++){
        bool check_same = 1;
        for(int j = 0; j < size_s; j++){
            if(s_inverted[j] != s[(i+j)%size_s]){
                check_same = 0;
                break;
            }
        }
        if(check_same) {
            ok = 1; break;
        }
    }
    
    cout << ok << endl;
    
    return 0;
}