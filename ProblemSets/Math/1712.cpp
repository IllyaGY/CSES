#include <iostream>

using namespace std;
typedef long long ll;

typedef long long ll;

#define MOD  1000000007

ll pow_mod(ll base, ll exp, ll mod = 1000000007) {
    ll f = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) f = (f * base) % mod;

        base = (base * base) % mod;

        exp /= 2;
    }
    return f;
}

int main(){
    int t; cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << pow_mod(a, pow_mod(b, c, MOD-1), MOD) << endl;
    }
    return 0;
}


