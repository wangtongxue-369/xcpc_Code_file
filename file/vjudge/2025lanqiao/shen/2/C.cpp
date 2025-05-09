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
string zx, hx;
void dfs(string l, string r)
{
    if (l.size())
    {
        cout << r[r.length() - 1];
        ll p = l.find(r[r.length() - 1]);
        dfs(l.substr(0, p), r.substr(0, p));
        dfs(l.substr(p + 1), r.substr(p, r.length() - p - 1));
    }
}
void solve()
{
    cin >> zx >> hx;
    n = zx.length();
    dfs(zx, hx);
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
