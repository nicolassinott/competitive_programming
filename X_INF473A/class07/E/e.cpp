#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> topological_sort(vector<vector<int>>& dependence_graph) {
    int n = dependence_graph.size();
    vector<int> result;
    vector<int> in_degree(n, 0);

    // Calculate the in-degree of each vertex
    for (int u = 0; u < n; u++) {
        for (int v : dependence_graph[u]) {
            in_degree[v]++;
        }
    }

    // Enqueue all the vertices with in-degree 0
    queue<int> q;
    for (int u = 0; u < n; u++) {
        if (in_degree[u] == 0) {
            q.push(u);
        }
    }

    // Perform topological sorting
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : dependence_graph[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    return result;
}

int main() {
    int n; cin >> n;
    
    cin.ignore();
    string line;
    
    vector<vector<int>> dependance_graph(n);
    vector<vector<int>> forward_graph(n);

    unordered_map<string,int> index_mp;
    vector<string> name_mp(n);

    int idx = 0;

    string parent, child;
    for(int i = 0; i < n; i++){
        getline(cin,line); stringstream ss(line);
        ss >> child; child.pop_back();
        if(!index_mp.count(child)) {
            index_mp[child] = idx;
            name_mp[idx] = child;
            idx++;
        }
        while (ss >> parent){
            if(!index_mp.count(parent)){
                index_mp[parent] = idx;
                name_mp[idx] = parent;
                idx++;
            }
            dependance_graph[index_mp[parent]].push_back(index_mp[child]);
            forward_graph[index_mp[child]].push_back(index_mp[parent]);
        } 
    }

    string start; cin >> start;
    int idx_start = index_mp[start];

    vector<int> necessary_nodes(n);
    vector<int> stack;

    stack.push_back(idx_start);
    necessary_nodes[idx_start] = 1;

    while(!stack.empty()){
        idx = stack.back(); stack.pop_back();
        for(int next : dependance_graph[idx]){
            if(!necessary_nodes[next]){
                necessary_nodes[next] = 1;
                stack.push_back(next);
            }
        }
    }
    
    vector<int> topologial_sorting = topological_sort(dependance_graph);

    for(int node : topologial_sorting){
        if(necessary_nodes[node]){
            cout << name_mp[node] << endl;
        }
    }

    return 0;
}