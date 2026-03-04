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
    string s;
    cin >> s;
    vector<int> mp(26, 0);
    for (auto &i : s) mp[i-'a']++;
    ll top = f[s.size()];
    ll bottom = 1;
    for (auto &i : mp) {
        if (i) bottom = (bottom * f[i]) % mod;
    }
    cout << top * (pow_mod(bottom, mod-2) % mod) % mod;
    return 0;

}

