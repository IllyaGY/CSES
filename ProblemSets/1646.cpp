#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> v;
    ll n, q;
    cin >> n >> q;
    while(n--){
      ll i;
      cin >> i;
      v.push_back(i + (v.size() ? v.back() : 0));
    }

    while(q--){
        ll l, r;
        cin >> l >> r;
        l--; r--;
        cout << v[r] - (l ? v[l - 1] : 0) << "\n";
    }
    return 0;

}

