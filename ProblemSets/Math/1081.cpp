#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;


int main(){
    int t; cin >> t;
    vector<ll> v (1000001, 0); // by default all of them have 1 and themselves as divider
    ll mx_val = 1;
    ll mx = 1;
    while (t--)
    {
        ll val; cin >> val; v[val]++; mx_val = max(mx_val, val);
    }
    for (ll i = 2; i <= mx_val; i++)
    {
        ll ct = 0;
        ll val = 1;
        while (i * val <= mx_val && ct < 2)
        {
            if (v[i*val] != 0) ct+=v[i*val];
            val++;
        }
        if (ct > 1) mx = i;
    }
    cout << mx;
    return 0;
}


