#include <bits/stdc++.h>
using namespace std;

bool touch(vector<int>& story1, vector<int>& story2){
    int w1, h1, x1, y1, w2, h2, x2, y2;
    w1 = story1[0]; h1 = story1[1]; x1 = story1[2]; y1 = story1[3]; 
    w2 = story2[0]; h2 = story2[1]; x2 = story2[2]; y2 = story2[3]; 

    if(x2 >= x1 + w1 || x2+w2 <= x1 || y2 >= y1 + h1 || y2+h2 <= y1) return 0;
    return 1;
}

void backtracking(int last_triangle, vector<vector<int>>& position_table, vector<bool>& seen, vector<int>& curr_stories, int& max_area, int area, int counter){
    if(counter == position_table.size()) return;

    for(int i = last_triangle; i < position_table.size(); i++){
        if(seen[i]) continue;
        
        bool touched = 0;
        for(int el : curr_stories){
            if(touch(position_table[i], position_table[el])){
                touched = 1;
                break;
            } 
        }
        if(touched) continue;

        seen[i] = 1;
        area += position_table[i][4];
        int old_area = area;

        curr_stories.push_back(i);
        backtracking(i + 1,position_table, seen, curr_stories, max_area, area, counter + 1);
        curr_stories.pop_back();
        max_area = max(area, max_area);
        area -= position_table[i][4];
        seen[i] = 0;
    }
}

int main(){
    int n;

    while(cin >>n){
        if(n == 0) break;
        vector<vector<int>> position_table(n, vector<int>(5));
        vector<bool> seen(n,0);

        // set<vector<bool>> checked_solutions; 
 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 4; j++){
                cin >> position_table[i][j];
            }
            position_table[i][4] = position_table[i][0] * position_table[i][1]; 
        }

        int max_area = 0;
        int counter = 0;
        int area = 0;

        vector<int> curr_stories;

        backtracking(0,position_table, seen, curr_stories, max_area, area, counter);

        cout << max_area << endl;
    }

    return 0;
}
