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
ll _ = 1, n, m, ans = 0l; // a[1010][1010], f[1010][2020];
void solve()
{
    ll x;
    ll k;
    cin >> n >> m >> k;
    vector<vector<ll>> a(n + 10, vector<ll>(k + 10, INF));
    for (int i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {

            // cin>>a[i][j];
            cin >> x;
            a[i][x] = min(a[i][x], j);
        }
    }
    for (int j = 1; j <= k; j++)
    {
        ll minn = 1e18;
        for (int i = 1; i <= n; i++)
        {
            minn = min(minn, a[i][j]);
            a[i][j] = minn;
        }
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        bool flag = 1;
        ll maxn = 0;
        for (int j = 1; j <= k; j++)
        {
            if (a[i][j] > m)
            {
                flag = 0;
                break;
            }
            maxn = max(maxn, a[i][j]);
        }
        if (flag)
        {
            ans += m - maxn + 1;
        }
    }
    cout << ans << '\n';
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