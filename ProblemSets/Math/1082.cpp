#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;

#define MOD 1000000007
#define INV2 500000004 // inverse of 2 mod MOD
using i128 = __int128_t;


int main(){

    ll n; cin >> n;
    ll s = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll q = n / i;
        ll r = i + (n % i) / q;

        s+= (q * (((i128)((i + r) % MOD) * ((r - i + 1) % MOD) % MOD) * INV2) % MOD) % MOD;
        s%=MOD;
        i = r;
    }
    cout << s;
    return 0;
}


