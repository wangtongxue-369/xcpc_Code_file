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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n >> m;
    set<PII> se;
    for (int i = 1; i < n; i++)
    {
        cout << i << ' ' << i << '\n';
        cout << i << ' ' << i + 1 << '\n';
        se.insert({i, i});
        se.insert({i, i + 1});
    }
    cout << n << ' ' << n << '\n';
    se.insert({n, n});
    cout << n << ' ' << 1 << '\n';
    se.insert({n, 1});
    ll p = 2 * n;
    if (p >= m)
    {
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (se.contains({i, j}))
            {
                continue;
            }
            else
            {
                cout << i << ' ' << j << '\n';
                se.insert({i, j});
                p++;
            }
            if (p >= m)
            {
                return;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}