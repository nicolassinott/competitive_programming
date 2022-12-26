#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int t;
    cin >> t;
    
    int n;
    
    while(t--){

        cin >> n;
        vector<int> nList;
        
        int it = n;
        
        while(it--){
            int temp;
            cin >> temp;
            nList.push_back(temp);
        }
        
        int left = 0;
        int right = INT_MAX;
        bool x = 0;
        
        for(int i = 1; i < n; i++){
            if(nList[i] > nList[i-1])
                right = min(right, (nList[i] - nList[i-1])/2 + nList[i-1]);
            
            else if (nList[i] < nList[i-1])
                left = max(left, (nList[i-1] - nList[i] + 1)/2 + nList[i]);
            
            if(left > right){
                x = 1;
                break;
            }
        }
        
        if(x)
            cout << -1 << '\n';
        else
            cout << left << '\n';
    }
    
    return 0;
}