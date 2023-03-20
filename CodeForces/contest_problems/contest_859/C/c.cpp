#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string st; cin >> st;
        vector<int> parity(26); // -1 impar, 1 par
        parity[0] = 0;
        bool broke = 0;

        for(int i = 0; i < n; i++){
            if (parity[st[i] - 'a'] == 0){
                if(i % 2 == 0){
                    parity[st[i] - 'a'] = 1;
                } else {
                    parity[st[i] - 'a'] = -1;
                }
                
            } else if ((parity[st[i] - 'a'] == -1 && i % 2 == 0) || (parity[st[i] - 'a'] == 1 && i % 2 == 1)){
                broke = 1;
                cout << "NO" << endl;
                break;
            }
        }

        if(!broke) cout << "YES" << endl;
    }

    return 0;
}