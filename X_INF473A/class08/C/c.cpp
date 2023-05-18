#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class TrieNode {
public:
    TrieNode* children[26];
    bool end_word;
    ll times_crossed;

    TrieNode() {
        memset(children, NULL, sizeof(children));
        end_word = false;
        times_crossed=0;
    }
};

int main(){
    ll n; cin >> n;

    TrieNode trie;

    for(int i = 0; i < n; i++){
        ll instances = 0;
        string word; cin >> word;
        TrieNode* path = &trie;

        for(char ch : word){
            int pos = ch - 'a';
            if(!path->children[pos]){
                path->children[pos] = new TrieNode();
            }
            
            path = path->children[pos];
            instances = path->times_crossed;
            path->times_crossed++;
        }

        cout << instances << endl;
    }


    return 0;
}