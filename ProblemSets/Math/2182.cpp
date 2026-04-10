#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;

#define MOD 1000000007
#define INV2 500000004 // inverse of 2 mod MOD
using i128 = __int128_t;

ll pow_mod(ll base, ll exp, ll mod = 1000000007) {
    ll f = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) f = ((i128)f * base) % mod;

        base = ((i128)base * base) % mod;

        exp /= 2;
    }
    return f;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll pd = 1;
    ll nd = 1;
    ll sd = 1;
    ll nd_exp = 1;
    //MOD-1 for the power, in case it s too bit, so we could cycle it
    for (ll i = 1; i <= n; i++) {
        ll x, k;
        cin >> x; cin >> k;

        ll tri = (ll)((i128)k * (k + 1) / 2 % (MOD - 1));
        ll exp_x = (ll)((i128)nd_exp * tri % (MOD - 1));

        pd = (i128)pow_mod(pd, k + 1)
           * pow_mod(x, exp_x) % MOD;

        nd = (i128)(nd * (k + 1)) % MOD;
        nd_exp = (i128)nd_exp * (k + 1) % (MOD - 1);

        ll sum_cnt = (i128)(pow_mod(x, (k + 1) % (MOD-1)) - 1)
                * pow_mod( (x - 1), MOD - 2) % MOD;

        sd = (i128)sd * sum_cnt % MOD;

    }

    cout << nd << " " << sd << " " << pd;
    return 0;
}


