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
void dfs(ll c, ll x)
{
    if (c == n - 1)
    {
        ll p1 = 0, p2 = 0;
        if (x & (1ll << (n - 1)))
        {
            p1 = 1;
        }
        cout << p1;
        for (int i = n - 2; i >= 0; i--)
        {
            p1 = 0, p2 = 0;
            if (x & (1ll << (i + 1)))
            {
                p1 = 1;
            }
            if (x & (1ll << i))
            {
                p2 = 1;
            }
            cout << (p1 ^ p2);
        }
        cout << '\n';
        return;
    }
    dfs(c + 1, x * 2 + 0);
    dfs(c + 1, x * 2 + 1);
}
void solve()
{
    cin >> n;
    vector<ll> ve;
    dfs(0, 0);
    dfs(0, 1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
