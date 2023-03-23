#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    while(1){
        cin >> n;
        if(!n) break;

        //computes the highest area
        // two pointers problem, looks at the area 
        // and stores max
        // takes the one that reduces the least

        int left = 0; int right = 0;
        int max_area = 0; int curr_area = 0;
        int min_height = -1;

        int curr_height;

        while(left < n){
            cin >> curr_height;
            right++;

            if(min_height == -1) min_height = curr_height;
            
            min_height = min(curr_height, min_height);
            curr_area = min_height * (right - left);
            max_area = max(max_area, curr_area);

            


        } 

        cout << max_area;
    }

    return 0;

}