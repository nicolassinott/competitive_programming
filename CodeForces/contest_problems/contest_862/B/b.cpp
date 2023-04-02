#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        string str; cin >> str;

        vector<int> first_occurence(26,0);

        char smallest_char = str[0];

        for(int i = 1; i < n; i++){
            if(str[i] < smallest_char){
                smallest_char = str[i];
            }
            if(str[i] < smallest_char && !first_occurence[str[i] - 'a']){
                first_occurence[str[i] - 'a'] = i;
            } else if (str[i] == smallest_char) {
                first_occurence[str[i] - 'a'] = i;
            }
        }

        int change_index = -1;

        for(int i = 0; i < 26; i++){
            if(first_occurence[i]) {
                change_index = first_occurence[i];
                break;
            }
        }

        if(change_index == -1) cout << str << endl;

        else {
            string new_str = ""; new_str += str[change_index];

            new_str += str.substr(0, change_index) + str.substr(change_index + 1, str.size());

            cout << new_str << endl;
        }

    }

    return 0;
}