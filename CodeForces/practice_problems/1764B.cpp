#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int t;
    cin >> t;
    
    int n, count;
    
    while(t--){
        
        count = 0;
        cin >> n;
        
        int m_gcd, temp;
        
        for(int i = 0; i < n; i++){
            cin >> temp;
            if(i == 0)
                m_gcd = temp;
            else
                m_gcd = __gcd(m_gcd, temp);
        }
        cout << temp / m_gcd << "\n";
    }

    return 0;
}