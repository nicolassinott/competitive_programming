#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    int N = 2*100000 + 1;

    while(t--){
        string s; cin >> s;
        if(s.size() == 1){
            cout << 0 << endl;
            continue;
        }

        char letter;

        int min_max_size = N - 2;

        for(int i = 0; i < 26; i++){
            letter = 'a' + i;
            
            int max_size = 0; int size = 0;
            for(char ch : s){
                if(ch == letter){
                    size = 0;
                } else {
                    size++;
                }                
                max_size = max(max_size, size);
            }

            min_max_size = min(min_max_size, max_size);
        }

        if(min_max_size == 0){
            cout << 0 << endl;
        } else {
            int operations = 0;

            while(min_max_size != 1){
                min_max_size /= 2;
                operations++;
            }

            operations++;
            cout << operations << endl;
        }
    }

    return 0;
}