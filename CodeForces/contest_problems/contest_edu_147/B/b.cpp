#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        //dont forget to add 1

        vector<int> a(n,0);
        // vector<int> b(n,0);

        int el;

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int lmax, rmax, maxsize;
        lmax = 0; rmax = 0; 

        int l, size;
        l = 0; 

        int previous; cin >> previous;

        bool saw_change = 0;
        bool passed_changed = 0;

        for(int i = 1; i < n; i++){
            cin >> el;
            if(passed_changed) continue;

            if(el < previous) {
                if(!saw_change){
                    l = i;
                } else {
                    lmax = l; rmax = i - 1;
                    passed_changed = 1;
                }

                // if (i - 1 - l <= rmax - lmax){
                //     l = i;
                // } else {
                //     lmax = l; rmax = i - 1;
                //     l = i; 
                // }
            }
            if(el != a[i]){
                saw_change = 1;
            }
            previous = el;
        }

        if(!passed_changed){
            rmax = n-1; lmax = l;
        }

        // if(n - 1 - l > rmax - lmax){
        //     lmax = l; rmax = n - 1;
        // }

        lmax++; rmax++;

        cout << lmax << ' ' << rmax << endl;

    }

    return 0;
}