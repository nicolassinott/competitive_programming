#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; int k;
    int curr_number;
    int counter = 0;

    cin >> n; cin >> k;

    while(n--){
        cin >> curr_number;
        if(!(curr_number%k)) counter++;
    }

    cout << counter << endl;
    return 0;
}