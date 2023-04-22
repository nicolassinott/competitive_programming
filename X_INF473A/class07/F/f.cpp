#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    ll n; cin >> n;

    vector<ll> frequency(n,0);
    vector<ll> elements(n);

    bool found = 0;

    ll el;
    for(ll i = 0; i < n; i++){
        cin >> el;
        if(el == n+1) found = 1;
        frequency[el - 1]++;
        elements[i] = el - 1;
    }
    if(!found) {
        cout << "Error" << "\n";
        return 0;
    } 

    priority_queue<int, vector<int>, greater<int>> leafs;
    for(int i = 0; i < n; i++) if(!frequency[i]) leafs.push(i);
    queue<int> print_queue;

    for(int i = 0; i < n; i++){
        if(leafs.empty()) {
            cout << "Error\n";
            return 0;
        }
        print_queue.push(leafs.top()); leafs.pop();
        frequency[elements[i]]--;
        if(!frequency[elements[i]]) leafs.push(elements[i]);
    }

    while(!print_queue.empty()){
        int p = print_queue.front(); print_queue.pop();
        cout << p+1 << "\n";
    }

    return 0;
}