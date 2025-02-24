#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> f(n + 100, 0);
    f[1] = 0;
    ll x = 0;
    ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (x == 0 && a[i] >= a[i - 1])
        {
            continue;
        }
        if (a[i] == 1)
        {
            cout << -1 << '\n';
            return;
        }
        double A = log(1.0 * a[i - 1]) / log(1.0 * a[i]);
        ll d = ceil(log2(A) + x);
        f[i] = max(0ll, d);
        x = f[i];
        ans += f[i];
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
