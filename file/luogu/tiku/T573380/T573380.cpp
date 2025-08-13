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
ll _ = 1, n, m, ans = 0;
ll a, b, c, k;
void dfs(ll t)
{
    if (t < k)
    {
        cout << t << '\n';
        ans++;
    }
    else
    {
        return;
    }
    dfs(t * 10 + a);
    dfs(t * 10 + b);
    dfs(t * 10 + c);
}
void solve()
{
    cin >> a >> b >> c >> k;
    if (c < b)
    {
        swap(b, c);
    }
    if (b < a)
    {
        swap(a, b);
    }
    if (c < b)
    {
        swap(c, b);
    }
    dfs(a);
    dfs(b);
    dfs(c);
    // cout << ans - 1 << '\n';
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