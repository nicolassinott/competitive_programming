#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;

    while(t--){
        string number; cin >> number;

        int count = 0;

        if(number[0] == '?') {
            count = 9;
        } else if (number[0] != '0') {
            count = 1;
        } else {
            count = 0;
        }

        for(int i = 1; i < number.size(); i++){
            if (number[i] == '?') count *= 10;
        }

        cout << count << endl;

    }

    return 0;
}