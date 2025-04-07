#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    ll k, x;
    cin >> n;
    cin >> k;
    vector<vector<ll>> ve(n + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cin >> x;
            ve[i].push_back(x);
        }
    }
    vector<vector<ll>> f(n + 1, vector<ll>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        ll maxn = 0;
        if (i == 0)
        {
            for (int j = 0; j < k; j++)
            {
                maxn = max(maxn, ve[i][j]);
                f[i][j] = maxn;
            }
            continue;
        }
        for (int j = 0; j < k; j++)
        {
            maxn = max(maxn, f[i - 1][j] + ve[i][j]);
            f[i][j] = maxn;
        }
    }
    cout << f[n - 1][k - 1] << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
