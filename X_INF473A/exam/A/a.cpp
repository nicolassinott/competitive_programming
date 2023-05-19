#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int nfiles; cin >> nfiles;

    int total_bytes = 0;

    // load spaces
    vector<int> spaces;
    for(int file = 0; file < nfiles; file++){
        int nlines; cin >> nlines;
        for(int line = 0; line < nlines; line++){
            int nspaces; cin >> nspaces;
            total_bytes += nspaces;
            spaces.push_back(nspaces);
        }
    }

    // cout << spaces.size() << endl;

    // for(int space : spaces) {
    //     cout << space << ' ';
    // }
    // cout << endl;

    int best_tab_size=-1;
    int smallest_bytes=80*(spaces.size());

    // cout << smallest_bytes << endl;

    for(ll tab_size = 1; tab_size < 80; tab_size++){
        int curr_bytes = 0;

        for(int n_spaces : spaces){
            int tabs_used = n_spaces/tab_size;
            curr_bytes += tabs_used + (n_spaces - tab_size * tabs_used);
        }

        if(curr_bytes < smallest_bytes){
            smallest_bytes = curr_bytes;
            best_tab_size = tab_size;
        }
    }

    cout << best_tab_size << endl;
    cout << total_bytes - smallest_bytes << endl; 

    return 0;
}