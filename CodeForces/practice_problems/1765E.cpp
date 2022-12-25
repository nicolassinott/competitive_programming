#include <iostream>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    int n, a, b;
    
    while(t--){
        cin >> n;
        cin >> a;
        cin >> b;
        
        if(b < a){
            cout << 1 << "\n";
        } else {
            if(n%a == 0){
                cout << n / a << "\n"; 
            } else {
                cout << n / a + 1 << "\n";
            }
        }
    }

    return 0;
}