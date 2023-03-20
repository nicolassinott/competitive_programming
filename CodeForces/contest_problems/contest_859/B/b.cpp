#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        int sum_pair = 0; int sum_odd = 0;
        while(n--){
            int new_number; cin >> new_number;
            if(new_number % 2) {
                sum_odd += new_number;
            } else {
                sum_pair += new_number;
            }
        }

        if(sum_pair > sum_odd){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}