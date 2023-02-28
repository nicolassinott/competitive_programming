#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ll bin_search(vector<ll>& operations, ll target){
//     ll left = 0; ll right = operations.size();
//     ll middle;
//     while(left <= right){
//         middle = (left + right) / 2;
//         if(operations[middle] == target) return middle;
//         else if(operations[middle]) 
//     }
// }

void copy_vector(vector<ll>& original, vector<ll>& copy){
    int size = original.size();

    for (int i = 0; i < size; i++){
        copy[i] = original[i];
    }
}

int main(){
    int t; cin >> t;

    while(t--){
        ll n; cin >> n;
        vector<ll> elements(n);
        vector<ll> sorted_elements(n);

        vector<pair<int,int>> operations;

        bool all_same = 1;
        bool has_one = 0;
        ll previous_element = -1;

        // prepare the array
        for(ll i = 0; i < n; i++){
            cin >> elements[i];
            sorted_elements[i] = elements[i];
            if(!all_same && has_one) continue;

            if(elements[i] == 1) has_one = 1;

            if(i == 0) 
                previous_element = elements[i];
            else {
                if(previous_element != elements[i])
                    all_same = 0;
            }
        }

        if (all_same){
            cout << 0 << endl;
            continue;
        }
        else if (has_one){
            cout << -1 << endl;
            continue;
        }
            
        // executes the algorithm

        bool made_all_equal = 1;
        int index_smallest; int smallest_element;

        // cout << "Initially" << endl;
        // for(int j = 0; j < elements.size(); j++){
        //     cout << elements[j] << ' ';
        // }
        // cout << endl;
        

        while(made_all_equal){
            sort(sorted_elements.begin(), sorted_elements.end());

            smallest_element = sorted_elements[0];
            // index_smallest = std::binary_search(elements.begin(), elements.end(), smallest_element);

            for(int i = 0; i < n; i++){
                if(elements[i] == smallest_element) index_smallest = i;
            }

            for(int i = 0; i < n; i++){
                if(elements[i] == smallest_element) continue;
                made_all_equal = 0;

                while(smallest_element < elements[i]){
                    elements[i] = (elements[i] + smallest_element - 1) / smallest_element;
                    operations.push_back({i, index_smallest});
                }
            }
            
            if(made_all_equal) break;

            made_all_equal = 1;

            copy_vector(elements, sorted_elements);
        }

        // cout << "testing if it works:" << endl;
        // for(int j = 0; j < elements.size(); j++){
        //     cout << elements[j] << ' ';
        // }
        // cout << endl;

        cout << operations.size() << endl;

        for(int i = 0; i < operations.size(); i++){
            cout << operations[i].first + 1 << ' ' << operations[i].second + 1 << endl;
        }

    }

    return 0;
}