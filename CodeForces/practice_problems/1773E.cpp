#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
using namespace std;
 
int findSplit(vector<int> v, int target){
    int left = 0;
    int right = v.size();
    int middle;
        
    while(left <= right){
        middle = (right - left) / 2 + left;
            
        if(v[middle] > target){
                left = middle + 1; 
        } else{
                right = middle -1;
        }
    }
    
    return left;
}
 
int main(){
 
    int n;
    cin >> n;
    int split = 0;
    int merge = 0;
 
    priority_queue<vector<int>> pq;
    
    while(n--){
        int k;
        cin >> k;
        
        vector<int> temp;
        int prev = 0;
        
        while(k--){
            int tempInt;
            cin >> tempInt;
            
            if(tempInt > prev){
                prev = tempInt;
                temp.push_back(-tempInt);
            } else {
                split++;
                pq.push(temp);
                temp.clear();
                temp.push_back(-tempInt);
                prev = tempInt;
            }
        }
        
        pq.push(temp);
    }
    
    bool isNotFirst = 0;
    
    while(!pq.empty()){
        vector<int> first = pq.top();
        pq.pop();
        
        if(pq.empty()){
            if (isNotFirst){
                merge++;
            }
            break;
        }
            
        vector<int> second = pq.top();
        int n_second = second.size() - 1;
        int n_first = first.size() - 1;
        
        if(first[n_first] < second[0]){
            split++;
            int new_start = findSplit(first,second[0]); 
            vector<int> v_right(first.begin() + new_start, first.end());
            pq.push(v_right);
        }
        
        if(isNotFirst)
            merge++;
        else
            isNotFirst = 1;
    }
    
    cout << split << ' ' << merge << endl;
    
    return 0;
}