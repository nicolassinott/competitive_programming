#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, d; cin >> n >> m >> d;
    int count = 0;
    int day = 0;

    // vector<string> name_mp(n);
    unordered_map<string,int> index_mp;
    // vector<int> weights(n);
    vector<int> remaining_convince(n);
    vector<bool> already_convinced(n);

    vector<bool> already_heard(n);

    vector<vector<int>> graph(n);

    for(int i = 0; i < n; i++){
        string name; cin >> name;
        // name_mp[i] = name; 
        index_mp[name] = i;
        
        cin >> remaining_convince[i];
    }

    for(int i = 0; i < m; i++){
        string p1, p2; cin >> p1 >> p2;
        int n1, n2; n1 = index_mp[p1]; n2 = index_mp[p2]; 
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    
//a cada pessoa nova convencida fazemos um -- nos vizinhos dela
//salvamos a lista de novas pessoas que se convenceram
//se a lista esta empty podemos parar a iteracao

    vector<int> new_convinced;
    string first; cin >> first; 
    new_convinced.push_back(index_mp[first]);
    already_convinced[index_mp[first]] = 1;
    already_heard[index_mp[first]] = 1;

    vector<int> next_new_convinced;

    while(!new_convinced.empty() && day < d){
        while(!new_convinced.empty()){
            int new_person = new_convinced.back(); new_convinced.pop_back();
            
            for(int person : graph[new_person]){
                remaining_convince[person]--;

                //update if person never heard the rumor
                if(!already_heard[person]){
                    count++;
                    already_heard[person] = 1;
                }

                // if person is convinced now add to the list
                if(!already_convinced[person] && !remaining_convince[person]){
                    next_new_convinced.push_back(person);
                    already_convinced[person] = 1;
                }
            }
        }

        while(!next_new_convinced.empty()){
            int p = next_new_convinced.back(); next_new_convinced.pop_back();
            new_convinced.push_back(p);   
        }
        day++;
    }

    cout << count << endl;

    return 0;
}