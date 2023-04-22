#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N = 100 + 1;
    int start; cin >> start;
    vector<int> graph(N);
    
    cin.ignore();
    string line;

    int parent, child;
    while(getline(cin,line) && line != "-1" ){
        stringstream ss(line);    
        ss >> child; 
        while (ss >> parent) graph[parent] = child;
    }

    vector<int> path; path.push_back(start);

    while(graph[start] != 0){
        path.push_back(graph[start]);
        start = graph[start];
    }

    for(int num : path){
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}