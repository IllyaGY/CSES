#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vec;
typedef vector<bool> vecb;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n, x ;
    cin >> n >> x;
    vector<ll> bp(n + 1, 0);
    vector<ll> pages (n + 1, 0);
    vector<vector<ll>> prices(2, vector<ll>(x + 1, 0));

    for (ll i = 1; i <= n; i++)
    {
        cin >> bp[i];

    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> pages[i];

    }
    for (ll i = 1; i <= n ; i++)
    {
        for (ll j = 1; j <= x; j++)
        {
            prices[1][j] = max(prices[0][j], prices[1][j-1]);
            if (j - bp[i] >= 0) prices[1][j] = max(prices[1][j], prices[0][j-bp[i]] + pages[i]);
        }
        swap(prices[1],prices[0]);
    }

    cout << prices[0][x] << endl;
    return 0;



}