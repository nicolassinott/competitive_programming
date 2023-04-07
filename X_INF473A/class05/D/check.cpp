#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    string s; cin >> s;

    int count = 0;

    for(char ch : s){
        count += (ch - 'a') + 1;
    }

    cout << count << endl;
}