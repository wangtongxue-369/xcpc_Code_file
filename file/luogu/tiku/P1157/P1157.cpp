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
bool vis[MAXN];
void dfs(ll r, ll d)
{
    if (r == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 1)
            {
                cout << setw(3) << i;
            }
        }
        cout << '\n';
        return;
    }
    // cout << "! " << r << ' ' << d << '\n';
    for (int i = d + 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            dfs(r - 1, i);
            vis[i] = 0;
        }
    }
}
void solve()
{
    ll r;
    cin >> n >> r;
    dfs(r, 0);
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