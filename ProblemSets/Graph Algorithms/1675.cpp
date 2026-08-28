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

    ll unite_nodes(ll a, ll b, ll w)
    {

        a = get_parent(a);
        b = get_parent(b);

        if (a == b) return 0;

        if (size[b] > size[a]) swap(a,b);

        parent[b] = a;
        size[a] += size[b];


        return w;
    }


};

void kruskal(vector<pair<ll, pair<ll,ll>>>& edges, DSU& dsu, ll& min_size)
{
    for (auto edge : edges)
    {
        ll a = edge.second.first, b = edge.second.second;
        ll w = edge.first;

        a = dsu.get_parent(a);
        b = dsu.get_parent(b);

        if (a == b) continue;

        ll cost = dsu.unite_nodes(a, b, w);

        min_size += cost;

    }
}



int main ()
{
    DSU dsu;
    ll n, m; cin >> n >> m;
    vector<pair<ll, pair<ll,ll>>> edges;
    ll min_size = 0;
    while (m--)
    {
        ll a,b,w; cin >> a >> b >> w;
        edges.push_back({w, {a,b}});
    }
    sort(edges.begin(), edges.end());

    kruskal(edges, dsu, min_size);

    if (dsu.size[dsu.get_parent(1)] != n) cout << "IMPOSSIBLE\n";
    else cout << min_size << '\n';
    return 0;

}