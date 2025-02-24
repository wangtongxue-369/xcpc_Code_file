#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 5000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = a[i] - a[i - 1];
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << f[i] << ' ';
    // }
    // cout << '\n';
    while (p--)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        f[l] += x;
        f[r + 1] -= x;
    }
    p = 0;
    ll minn = f[1];
    for (int i = 1; i <= n; i++)
    {
        p += f[i];
        minn = min(minn, p);
    }
    cout << minn << '\n';
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
