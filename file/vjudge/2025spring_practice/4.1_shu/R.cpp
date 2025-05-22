#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN]; // ha[MAXN][2];
vector<array<ll, 2>> ve(MAXN + 10);
ll son[MAXN];
int count(int x)
{
    if (x == -1)
        return 0;
    son[x] = count(ve[x][0]) + count(ve[x][1]) + 1;
    return son[x];
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll u, v;

    for (ll i = 1; i <= n; i++)
    {
        cin >> ve[i][0] >> ve[i][1];
    }
    count(1);
    function<bool(ll x, ll y)> dfs = [&](ll x, ll y) -> bool
    {
        if (x == -1 && y == -1)
        {
            return 1;
        }
        if (x == -1 || y == -1)
        {
            return 0;
        }
        if (a[x] != a[y])
        {
            return 0;
        }
        return dfs(ve[x][0], ve[y][1]) && dfs(ve[x][1], ve[y][0]);
    };
    ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (dfs(i, i))
        {
            ans = max(ans, son[i]);
        }
    }
    cout << ans << '\n';
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