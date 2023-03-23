#include <bits/stdc++.h>
using namespace std;


void quick_sort(long& counter, vector<long>& A){
    if(A.size() < 2) return;

    long pivot = A[0];

    vector<long> right_vec; vector<long> left_vec;
    long bigger = 1;

    for(long i = 1; i < A.size(); i++){
        if(A[i] < pivot){
            left_vec.push_back(A[i]); 
            counter += bigger;
        } else {
            right_vec.push_back(A[i]); 
            bigger++;
        }
    }

    quick_sort(counter, right_vec); quick_sort(counter, left_vec); 
}

int main(){
    long t; cin >> t;
    long n;
    long counter = 0;

    while(t--){
        cin >> n;
        vector<long> A(n);
        for(long i = 0; i < n; i++){
            cin >> A[i]; 
        }

        quick_sort(counter, A);
        cout << counter;
        if(t) cout << endl;
        counter = 0;

    }

    return 0;
}