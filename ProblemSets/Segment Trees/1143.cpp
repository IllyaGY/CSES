#include <iostream>
using namespace std;

typedef long long ll;


const int N = 200000;
ll arr[N], tree[4 * N], ps[4 * N];
int idx[4 * N];

void build(int l, int r, int pos) {
    static int ctr = 1;
    if (l == r) {
        tree[pos] = arr[l];
        idx[pos] = ctr;
        ctr++;
        return;
    }

    int middle = (l + r) / 2;
    build(l, middle, 2 * pos);
    build(middle + 1, r, 2 * pos + 1);
    tree[pos] = max(tree[2 * pos],tree[2 * pos + 1]);
}



int query(int tree_l, int tree_r, int pos, ll val) {
    if (tree_l == tree_r) {
        if ( tree[pos] >= val)
        {
            tree[pos]-=val;
            return idx[pos];
        }
        return 0;
    }

    int middle = (tree_l + tree_r) / 2;
    int room = 0;
    if (tree[pos*2] >= val) {
        room = query(tree_l, middle, 2 * pos, val);
    }
    else {
        room = query(middle + 1, tree_r, 2 * pos + 1, val);
    }
    if (room) tree[pos] = max(tree[pos*2],tree[pos*2 + 1]);
    return room;
}

const int MAX = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(0, n - 1, 1);

    while (m--) {
        int guests; cin >> guests;
        cout << query(0, n-1 , 1, guests) << " ";
    }

    return 0;
}