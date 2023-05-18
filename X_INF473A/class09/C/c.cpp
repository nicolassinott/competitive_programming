#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    while(t--){
        int k,w; cin >> k >> w;
        vector<char> words;
        string word; cin >> word;

        for(char ch : word) words.push_back(ch);

        for(int i = 1; i < w; i++){
            cin >> word;
            int common_size = 0;

            for(int left = 0; left < k; left++){
                if(words[words.size() - k + left] != word[0]) continue;
                
                bool got_end = 1;
                for(int right = left; right < k; right++){
                    if(words[words.size() - k + right] != word[right - left]) {
                        got_end = 0; break;
                    }
                }

                if(got_end) {
                    common_size = k - left;
                    break;
                } 
            }

            for(int j = common_size; j < k; j++) words.push_back(word[j]);
        }

        cout << words.size() << endl;

    }

    return 0;
}