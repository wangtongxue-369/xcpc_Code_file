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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN][3];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i][0] = 0;
        f[i][1] = 0;
        f[i][2] = 0;
    }
    f[0][0] = 1;
    f[0][1] = 1;
    f[0][2] = 0;
    for (int i = 1; i <= n; i++)
    {
        ll lx = i - a[i] - 1;
        // 想让 i 是 前面的一个的长度
        // lx-1如果是
        if (lx >= 0 && (f[lx][1] || f[lx][0]))
        {
            f[i][0] = 1;
        }
        ll rx = i + a[i];
        if (rx <= n && (f[i - 1][1] || f[i - 1][0]))
        {
            f[rx][1] = 1;
        }
    }
    if (f[n][0] || f[n][1])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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
