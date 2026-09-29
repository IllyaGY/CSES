#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

string arr[1001];

const ll MOD = 1000000007;

//TRY TO USE ARRAYS

int main()
{

    int n; cin >> n;
    vector<vector<ll>> dp (n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j-1] == '*') continue;

            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[n][n];
    return 0;
}