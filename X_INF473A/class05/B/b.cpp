#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll max_day; double fee; 
    cin >> max_day >> fee;

    double a = 100; double b = 0;
    double spot;

    while(max_day--){
        cin >> spot;
        a = max(a, b*spot - fee);
        b = max(b, (a-fee)/spot);
    }

    cout << a << endl;

    return 0;
}