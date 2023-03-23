#include <bits/stdc++.h>
using namespace std;

int first_occurency(vector<int>& occurrencies, int& target){
    int left = 0; int right = occurrencies.size() - 1; int middle;

    while(left <= right){
        middle = (right - left) / 2 + left;

        if(occurrencies[middle] == target) return middle;
        if(occurrencies[middle] > target) right = middle - 1;
        else left = middle + 1;
    }

    return left;
}

int main(){
    int n, q;
    cin >> n >> q;
    int current;
    int left; int right; int x; int k;

    unordered_map<int, vector<int>> occurence_map;

    for(int i = 0; i < n; i++){
        cin >> current;
        if(occurence_map.count(current)){
            occurence_map[current].push_back(i);
        } else {
            occurence_map[current] = {i};
        }
    }

    while(q--){
        cin >> left >> right >> x >> k;
        left--; right--;

        if(!occurence_map.count(x)){
            cout << -1 << endl;
            continue;
        }

        vector<int>& occurencies = occurence_map[x];

        int first_occur = first_occurency(occurencies, left);

        if(first_occur + k - 1 >= occurencies.size() || occurencies[first_occur + k - 1] > right){
            cout << -1 << endl;
            continue;
        }

        cout << occurencies[first_occur + k - 1] + 1 << endl;
    }

    return 0;
}