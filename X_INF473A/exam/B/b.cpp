#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double convert_time(double time){
    double inter_part = (int) time;
    double remainder = ((time - inter_part)/3)*5;
    return inter_part + remainder; 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, k, s; cin >> l >> k >> s;

    vector<int> map_real_computer(s+1,0);
    vector<int> completed_turns(s+1,0);

    // vector<pair<int,int>> performances; performances.push_back({-1,-1});
    vector<vector<int>> performances; performances.push_back({-1,-1,-1});

    for(int i = 0; i < l; i++){
        int nb; 
        // double time;
        string time;
        cin >> nb >> time;

        string inter_time_str = time.substr(0,2);
        string frac_time_str = time.substr(3,4);

        int inter_time = stoi(inter_time_str);
        int frac_time = stoi(frac_time_str);

        // update map
        if(map_real_computer[nb]){
            performances[map_real_computer[nb]][0] += inter_time;
            performances[map_real_computer[nb]][1] += frac_time;
            completed_turns[nb]++;
        } else {
            map_real_computer[nb] = performances.size();
            // map_computer_real[performances.size()] = nb;
            performances.push_back({inter_time,frac_time,nb});
            completed_turns[nb]++;
        }
    }

    vector<pair<double,int>> final_performances;

    for(int computer = 1; computer < performances.size(); computer++){
        int real_nb = performances[computer][2];
        if(completed_turns[real_nb] == k){
            pair<int,int> time_pair;
            time_pair.first = performances[computer][0];
            time_pair.second = performances[computer][1];

            int adj = time_pair.second / 60;
            double fraction = (double) (time_pair.second - 60 * adj)/100;
            double final_time = (double) (time_pair.first + adj) + fraction; // check 

            final_performances.push_back({final_time, real_nb});
        }
    }

    sort(final_performances.begin(), final_performances.end());

    for(auto a : final_performances){
        cout << a.second << endl;
    }

    return 0;
}