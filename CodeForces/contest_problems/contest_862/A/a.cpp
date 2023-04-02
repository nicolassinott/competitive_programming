#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        int a = 0;

        for(int i = 0; i < n; i++){
            int new_el; cin >> new_el;
            a ^= new_el;
        }

        if(!a) cout << 0 << endl;
        else {
            if(n%2 == 0) cout << -1 << endl;
            else cout << a << endl;
        }
    }

    return 0;
}