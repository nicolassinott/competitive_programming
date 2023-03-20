#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t; cin >> t;
    while(t--)
    {
        ll n, q; cin >> n >> q;
        vector<bool> parity(n);

        int curr_number; cin >> curr_number;
        parity[0] = curr_number %2;

        for(int i = 1; i < n; i++)
        {
            cin >> curr_number; curr_number %= 2;
            parity[i] = curr_number ^ parity[i-1];
        }

        bool total_parity = parity[n - 1];

        while(q--)
        {
            int l, r, k; cin >> l >> r >> k;
            l--; r--;
            bool k_parity = k % 2;
            bool query_parity = total_parity;
            if(l > 0)
                query_parity ^= (parity[r] ^ parity[l - 1]) ^ (k_parity * ((r - l + 1) % 2));
            else
                query_parity ^= (parity[r]) ^ (k_parity * ((r - l + 1) % 2));
            if(query_parity) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}