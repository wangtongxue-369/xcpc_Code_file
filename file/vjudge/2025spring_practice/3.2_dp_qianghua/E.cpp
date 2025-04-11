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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    f[n + 1] = 0;
    // f[n] = 1;
    for (int i = n; i >= 1; i--)
    {
        ll p = i + a[i] + 1;
        if (i + a[i] == n)
        {
            f[i] = 0;
            continue;
        }
        if (p > n)
        {
            f[i] = f[i + 1] + 1;
            continue;
        }
        f[i] = min(f[p], f[i + 1] + 1);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << f[i] << ' ';
    // }
    // cout << '\n';
    cout << f[1] << '\n';
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