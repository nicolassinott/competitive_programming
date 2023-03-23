#include <bits/stdc++.h>
using namespace std;


void quick_sort(int& counter, vector<int> A){
    if(!A.size()) return;
    if(A.size() == 1) return;
    //vector<int> newA(A.size());

    cout << "new call of function" << endl;
    // cout << "currently the counter is " << counter << endl;
    
    for(int i = 0; i < A.size(); i++){
        cout << A[i] << '|';
    }

    cout << endl;
    
    // int left = 0; int right = A.size() - 1;
    int pivot = A[0];

    vector<int> right_vec; vector<int> left_vec;
    int bigger = 1;

    for(int i = 1; i < A.size(); i++){
        if(A[i] < pivot){
            left_vec.push_back(A[i]); //newA[left] = A[i];
            // left++;
            counter += bigger;
        } else {
            right_vec.push_back(A[i]); // newA[right] = A[i];
            bigger++;
        }
    }

    //newA[right] = pivot;

    //vector<int> right_vec = vector<int>(newA.begin(), newA.begin() + left);
    //vector<int> left_vec = vector<int>(newA.begin() + right + 1, newA.end());
    // reverse(left_vec.begin(), left_vec.end());

    quick_sort(counter, right_vec); quick_sort(counter, left_vec); 

    // cout << "End of counter is " << counter;
}

int main(){
    int t; cin >> t;
    int n;
    int counter = 0;

    while(t--){
        cin >> n;
        vector<int> A(n);

        for(int i = 0; i < n; i++){
            cin >> A[i]; 
        }

        quick_sort(counter, A);
        cout << counter << endl;
        counter = 0;

    }

    return 0;
}