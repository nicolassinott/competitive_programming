#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    vector<vector<ll>> graph(f+1);

    for(int i = 1; i <= f; i++){
        if(d>0 && i-d >= 1) graph[i].push_back(i-d);
        if(u>0 && i+u <= f) graph[i].push_back(i+u);
    }

    queue<pair<int,int>> bfs; bfs.push({s,0});
    vector<bool> seen(f+1);

    bool found = 0;
    int n_steps;

    while(!bfs.empty()){
        auto [floor, steps] = bfs.front(); bfs.pop();
        if(seen[floor]) continue;
        seen[floor] = 1;

        if(floor == g) {
            found = 1;
            n_steps = steps;
            break;
        }

        for(int next : graph[floor]){
            if(!seen[next]) bfs.push({next, steps + 1});
        }
    }

    if(!found) cout << "use the stairs" << endl;
    else cout << n_steps << endl;

    return 0;
}