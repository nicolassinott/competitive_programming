#include <bits/stdc++.h>
using namespace std;

void recursion(vector<int>& solution_int_vector, vector<int>& curr_vector, vector<vector<int>>& bad_pairs, vector<int>& seen, int& count, int string_size, int& max_str_size){
    // checks if the best solution is already written
    if(string_size == max_str_size) {
        count++;
        if (solution_int_vector.empty()) {
            for(int i =0; i < max_str_size; i++) solution_int_vector.push_back(curr_vector[i]);
        }
    } else {
        for(int i = 0; i < max_str_size; i++){
            if (seen[i]) continue;

            if(curr_vector.size() != string_size){
                cout << "FAIL" << endl;
            }

            curr_vector.push_back(i);
            seen[i] = 1;
            
            if(!bad_pairs[i][curr_vector[string_size - 1]])
                recursion(solution_int_vector, curr_vector, bad_pairs, seen, count, string_size+1, max_str_size);

            curr_vector.pop_back();
            seen[i] = 0;
        }
    }

}

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;        
        vector<string> vector_list(n);
        vector<vector<int>> bad_pairs(n, vector<int>(n));
        unordered_map<string,int> str_map; 
        unordered_map<int, string> int_map;

        for(int i = 0; i < n; i++){
            string new_str; cin >> new_str;
            str_map[new_str] = i;
            int_map[i] = new_str;
        }
        
        int m; cin >> m;
        
        for(int i = 0; i < m; i++){
            string s1, s2; cin >> s1 >> s2;
            bad_pairs[str_map[s1]][str_map[s2]] = 1;
            bad_pairs[str_map[s2]][str_map[s1]] = 1;
        }

        int count = 0;
        vector<int> solution_int_vector;
        vector<int> curr_vector;
        vector<int> seen(n,0);
        int string_size = 0;
    
        for(int i = 0; i < n; i++){
            curr_vector.push_back(i);
            seen[i] = 1;
            recursion(solution_int_vector, curr_vector, bad_pairs, seen, count, string_size + 1, n);
            curr_vector.pop_back();
            seen[i] = 0;
        }

        cout << count << endl;
        for(int i = 0; i < n; i++) cout << int_map[solution_int_vector[i]] << ' ';
        cout << endl;  
    }

    return 0;
}
