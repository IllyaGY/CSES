#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

typedef long long ll;


int main(){
    int t; cin >> t;
    vector<ll> v (1000001, 2); // by default all of them have 1 and themselves as divider
    v[1] = 1; //has only 1
    for (ll i = 2; i * i <= 1000000; i++)
    {
        v[i*i]+=1;
        ll mult = i+1;
        while (i * mult <= 1000000)
        {
            v[i * mult++]+=2;
        }

    }
    while (t--)
    {
        int a;
        cin >> a;
        cout << v[a] << "\n";
    }
    return 0;
}


