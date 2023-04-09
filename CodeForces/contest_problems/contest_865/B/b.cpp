#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        int higher = 2*n - 1; int smaller = 1;

        while(higher > smaller){
            cout << higher << ' ';
            higher -= 2;
            cout << smaller << ' ';
            smaller += 2;
        }

        cout << endl;

        smaller = 2; higher = 2 * n - 2;
        while(higher > smaller){
            cout << smaller << ' ';
            smaller += 2;
            cout << higher << ' ';
            higher -= 2;
        }

        higher = 2*n;
        cout << n << ' ' << higher << endl;
    }

    return 0;
}