#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int max_sub_tree(vector<vector<pair<int,int>>>& adj, vector<int>& seen, vector<pair<int,int>>& stack, int& curr_node, int& curr_weight){
    for(auto [next, c] : adj[curr_node]){
        if(!seen[next]){
            seen[next] = 1;
            stack.push_back({next, curr_weight+c});
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n_islands, k; cin >> n_islands >> k;

    if(k >= 2){
        ll value = 0;
        for(int i = 0; i < n_islands-1; i++){
            int u, v, c; cin >> u >> v >> c;
            value += c;
        }

        cout << value << endl;
    } else {
        vector<vector<pair<int,int>>> adj(n_islands+1);

        vector<bool> seen_bigger_path(n_islands+1);

        for(int i = 0; i < n_islands-1; i++){
            int u, v, c; cin >> u >> v >> c;
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});    
        }

        ll global_max = 0;

        for(int i = 1; i < n_islands; i++){
            if(seen_bigger_path[i]) continue;
            vector<int> seen(n_islands+1);
            vector<pair<ll,ll>> stack;

            stack.push_back({i,0}); seen[i] = 1;
            ll max_weight = 0;

            while(!stack.empty()){
                pair<ll,ll> curr = stack.back(); stack.pop_back();
                ll curr_node = curr.first; ll curr_weight = curr.second;
                max_weight = max(max_weight, curr_weight);

                bool end_root = 1;

                for(auto [next, c] : adj[curr_node]){
                    if(!seen[next]){
                        seen[next] = 1;
                        stack.push_back({next, curr_weight+c});
                    }
                }            
            }
            
            global_max = max(global_max, max_weight);
        }

        cout << global_max << endl;
    }

    return 0;
}