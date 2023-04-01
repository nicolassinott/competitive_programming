#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> tasks(n,0);
    vector<int> free_time(m,0);

    for(int i = 0; i < n; i++) cin >> tasks[i];
    for(int i = 0; i < m; i++) cin >> free_time[i];

    sort(tasks.begin(), tasks.end()); 
    sort(free_time.begin(), free_time.end());

    int curr_task = 0;
    int counter = 0;

    for(int i = 0; i < m; i++){
        if(tasks[curr_task] <= free_time[i]){
            curr_task++; counter++;
        }
        if(counter == n) break;
    }

    cout << counter << endl;

    return 0;
}