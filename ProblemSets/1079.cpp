#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

ll pow_mod(ll base, ll exp, ll mod = 1000000000, ll mod_add = 7) {
    ll mod_f = mod + mod_add; // just in case it s not + 7;
    ll f = 1;
    base %= mod_f;
    while (exp >= 1) {
        if (exp & 1) f = (f * base) % mod_f;

        base = (base * base) % mod_f;

        exp /= 2;
    }
    return f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod = 1000000007;
    vector<ll> f(1000001, 1);
    for (int i = 1; i < f.size(); i++) f[i] = (f[i-1] * i) % mod;
    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll top = f[a];
        ll bottom = pow_mod(f[b] * f[a-b] % mod, 1000000005);
        cout << (top * bottom) % mod << "\n";
    }
    return 0;
}

