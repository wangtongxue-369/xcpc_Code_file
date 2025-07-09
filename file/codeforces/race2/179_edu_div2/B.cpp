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
    cin >> n >> m;
    ll w, h, l;

    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    ll s1 = f[n], s2 = f[n], s3 = f[n] + f[n - 1];
    // cout << s1 << ' ' << s2 << ' ' << s3 << '\n';
    for (int i = 1; i <= m; i++)
    {
        cin >> w >> h >> l;
        if (w > h)
        {
            swap(w, h);
        }
        if (l > h)
        {
            swap(l, h);
        }
        // cout << w << ' ' << h << ' ' << l << '\n';
        if ((s1 <= w) && (s2 <= l) && (s3 <= h))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    cout << '\n';
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