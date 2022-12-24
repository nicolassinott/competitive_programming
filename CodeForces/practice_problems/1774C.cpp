#include <iostream>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    int n, curr;
    
    while(t--){

        cin >> n;

        int previous;
        
        int possibleWinners = 1;
        
        for(int i = 1; i < n; i++){
            char c;
            cin >> c;
            curr = c - '0';
            
            
            if(i == 1){
                cout << 1 << ' ';
                previous = curr;
            } else {
                if (previous != curr){
                    possibleWinners = i;
                    previous = curr;
                }
                cout << possibleWinners << ' ';
            }
        }
        cout << "\n";
        
    }

    return 0;
}