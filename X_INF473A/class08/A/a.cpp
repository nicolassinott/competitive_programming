#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, q, s;

    cin >> n >> m >> q >> s;

    while(1){
        vector<vector<pair<ll,ll>>> graph(n);
        vector<bool> treated(n);
        vector<ll> distance(n, -1);

        distance[s] = 0;

        //pupulating graph
        for(ll i = 0; i < m; i++){
            ll u, v, w; cin >> u >> v >> w;
            graph[u].push_back({w,v});
            // graph[v].push_back({w,u});
        }

        //generating weights
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push({distance[s], s});

        while(!pq.empty()){
            auto[dist, node] = pq.top(); pq.pop();
            if(treated[node]) continue;
            
            distance[node] = min(distance[node], dist);

            for(auto const [weight, next] : graph[node]){
                if(treated[next]) continue;
                if(distance[next] == -1){
                    distance[next] = distance[node] + weight;
                } else {
                    distance[next] = min(distance[next], distance[node] + weight);
                }
                pq.push({distance[next], next});
            }
            
            treated[node]=1;
        }

        //queries
        for(ll i = 0; i < q; i++){
            ll q; cin >> q;
            if(distance[q] == -1) cout << "Impossible" << endl;
            else cout << distance[q] << endl;
        }

        cin >> n >> m >> q >> s;
        if(!n && !m && !q && !s) break;
        cout << endl;
    }

    return 0;
}