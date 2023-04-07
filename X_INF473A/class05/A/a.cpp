#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    int weight;
    vector<bool> has_solution(2001,0);
    has_solution[0] = 1;

    for(int i = 0; i < n; i++) {
        cin >> weight;
        for(int j = 2000 - weight; j >= 0; j--){
            if(has_solution[j]) has_solution[j + weight] = 1;
        }
    } 

    for(int i = 0; i < 1000; i++){
        if(has_solution[1000 + i]){
            cout << 1000 + i << endl;
            break;
        }
        if(has_solution[1000 - i]){
            cout << 1000 - i << endl;
            break;
        }
    }

    return 0;
}