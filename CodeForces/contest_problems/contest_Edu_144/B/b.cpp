#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// string solve(string& a, string& b, string to_ret){
    
    
//     return 'a';
// }

int main(){
    int t; cin >> t;

    while(t--){
        string a; string b;
        cin >> a >> b;
        int counter_ast = 0;
        int counter_letter = 0;
        string to_ret = "";

        // string current_equal;

        char previous_letter = 'a';

        if(a.size() < b.size()){
            string c = a;
            a = b; b = c;
        }

        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < b.size(); j++){
                if(a[i] == b[j]){
                    to_ret = to_ret + a[i];
                } else {
                    
                }
            }
        }

        for(int i = 0; i < b.size(); i++){
            if(a[i] == b[i]){
                to_ret = to_ret + a[i];
                counter_letter++;
                previous_letter = a[i];
            } else {
                if(previous_letter != '*'){
                    to_ret = to_ret + '*';
                    counter_ast++; 
                }
            }
        }

        if(a.size() > b.size() && to_ret[-1] != '*'){
            counter_ast++;
            to_ret = to_ret + '*';
        }

        if(counter_ast <= counter_letter){
            cout << "YES" << endl;
            cout << to_ret;
        } else {
            cout << "NO" << endl;
        }

    }
}