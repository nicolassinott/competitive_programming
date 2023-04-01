#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Trie {
public:
    bool is_end;
    vector<Trie*> next;

    Trie(): is_end(false), next(vector<Trie*>(26, nullptr)) {}
    ~Trie() {
        for (auto node : next)
            delete node;
    }
    void insert(const string& word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->next[c - 'a'])
                node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->is_end = true;
    }
    bool search(const string& word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->next[c - 'a'])
                return false;
            node = node->next[c - 'a'];
        }
        return node->is_end;
    }
    bool startsWith(const string& prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (!node->next[c - 'a'])
                return false;
            node = node->next[c - 'a'];
        }
        return true;
    }
};

int main() {
    Trie trie;
    string input_str; cin >> input_str; trie.insert(input_str);
    while(input_str != "#") trie.insert(input_str);


    // start e end, tem que tentar do start, start + 1, start + 2, etc ate end


    return 0;
}