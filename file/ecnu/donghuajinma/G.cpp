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
    ll op, k, x, l, r;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll pr = 0, t;
    for (int i = 1; i <= n; i++)
    {
        t = a[i];
        a[i] = a[i] - pr;
        pr = t;
    }
    while (m--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> k >> x;
            a[k] += x;
            a[k + 1] -= x;
        }
        else
        {
            cin >> l >> r;
            // 连续的相等的数量+1
            // log得到连相等的数量
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