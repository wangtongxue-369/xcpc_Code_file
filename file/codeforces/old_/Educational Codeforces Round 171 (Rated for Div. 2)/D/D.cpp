#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
ll ps[MAXN], s[MAXN];
ll f(ll id)
{
    if (id == 0)
    {
        return 0;
    }
    ll l = 0, r = n, mid, x = -1, pos, res;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (n * (n + 1) / 2 - (n - mid) * (n - mid + 1) / 2 < id)
        {
            x = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    pos = n * (n + 1) / 2 - (n - x) * (n - x + 1) / 2;
    res = ps[x] + b[x + id - pos] - b[x] - (id - pos) * a[x];
    return res;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        s[i] = b[n] - b[i - 1] - (n - i + 1) * a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + s[i];
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << f(r) - f(l - 1) << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
