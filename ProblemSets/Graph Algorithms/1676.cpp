#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
ll constexpr N = 2e5 + 1;


using namespace std;

struct DSU
{
    vector<ll> parent;
    vector<ll> size;

    DSU()
    {
        parent.resize(N);
        size.resize(N);
        for (ll i = 1; i <= N; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    ll get_parent(ll a)
    {
        if (parent[a] == a) return a;
        parent[a] = get_parent(parent[a]);
        return parent[a];
    }

    ll unite_nodes(ll a, ll b, ll& components)
    {

        a = get_parent(a);
        b = get_parent(b);

        if (a == b) return a;

        if (size[b] > size[a]) swap(a,b);

        parent[b] = a;
        size[a] += size[b];
        components--;

        return a;
    }


};

void kruskal(const pair<ll,ll> edge, DSU& dsu, pair<ll, ll>& max_pair, ll& components)
{

    ll a = edge.first, b = edge.second;

    a = dsu.get_parent(a);
    b = dsu.get_parent(b);

    ll larger_parent = dsu.unite_nodes(a, b, components);

    //first - parent with highest current size // second - current size
    if (max_pair.second >= dsu.size[larger_parent])
    {
        cout << components << " " << max_pair.second << '\n';
        return;
    }

    if (max_pair.first != larger_parent)
        max_pair.first = larger_parent;

    max_pair.second = dsu.size[larger_parent];

    cout << components << " " << max_pair.second << '\n';

}



int main ()
{
    DSU dsu;
    ll n, m; cin >> n >> m;
    pair<ll, ll> max_pair = {0, 0};
    ll components = n;
    while (m--)
    {
        ll a,b; cin >> a >> b;
        kruskal({a, b}, dsu, max_pair, components);
    }




    return 0;

}