#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int l, w; cin >> l >> w;

    if(w < l || w > 26*l){
        cout << "impossible" << endl;
        return 0;
    }

    vector<char> answer(l);

    for(int i = 0; i < l; i++){
        int average_size = w/(l - i);
        answer[i] = 'a' + (average_size - 1);
        w -= average_size;
    }

    string s(answer.begin(), answer.end());
    cout << s << endl;

    return 0;
}