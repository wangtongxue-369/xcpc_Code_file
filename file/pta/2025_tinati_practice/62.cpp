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
ll _ = 1, n, m, ans = 0, z[MAXN], q[MAXN];
vector<PII> ve(MAXN);
void dfs(ll zl, ll zr, ll ql, ll qr)
{
    if (zl >= zr || ql >= qr)
    {
        return;
    }
    ll p = q[ql];
    ll root;
    for (int i = zl; i <= zr; i++)
    {
        if (z[i] == p)
        {
            root = i;
            break;
        }
    }
    ll len = root - zl;
    if (len)
    {
        ve[p].first = q[ql + 1];
        dfs(zl, root - 1, ql + 1, ql + len);
    }
    if (qr - ql - len)
    {
        ve[p].second = q[ql + len + 1];
        dfs(root + 1, zr, ql + len + 1, qr);
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> z[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
    }
    dfs(1, n, 1, n);
    queue<ll> qu;
    qu.push(q[1]);
    cout << q[1];
    while (!qu.empty())
    {
        auto [l, r] = ve[qu.front()];
        qu.pop();
        if (r)
        {
            cout << " " << r;
            qu.push(r);
        }
        if (l)
        {
            cout << " " << l;
            qu.push(l);
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