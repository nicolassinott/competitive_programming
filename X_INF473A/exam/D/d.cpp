#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int,char> count_impulses(char ch, int days){
    //returns number of impulses and final char
    char final_char;
    int impulses = 0;  
    if(ch == 'A'){
        impulses = days/2;
        if(days%2) {
            final_char = 'B';
        } else {
            final_char = 'A';
        }
    } else {
        impulses = (days+1)/2;
        if(days%2) {
            final_char = 'A';
        } else {
            final_char = 'B'; 
        }
    }

    return {impulses, final_char};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s; cin >> s;
    int d; cin >> d;

    for(int i = 0; i < s.size(); i++){
        if(d <= 0) break;
        auto [impulses, final_char] = count_impulses(s[i], d);
        s[i] = final_char;
        d = impulses;
    }

    cout << s << endl;

    return 0;
}