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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
ll c[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        c[i] = a[i] + b[i];
    }
    ans = 0;
    ll l = 1;
    ll res = 0;
    res = a[l];
    for (int r = 1; r <= n; r++)
    {
        if (r + 1 <= n && c[r + 1] == c[l])
        {
            res += a[r + 1];
        }
        else
        {
            ans = max(ans, (r - l + 1) * res);
            l = r + 1;
            res = a[l];
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