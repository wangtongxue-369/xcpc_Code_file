#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 998244353;
const ll N = 1e3 + 10;
ll _ = 1, n, m, ans = 0, a[N], f[N];
ll jc[N];
bool cmp(ll s1, ll s2)
{
    return s1 > s2;
}
void init()
{
    ll res = 1;
    for (ll i = 1; i <= N; i++)
    {
        jc[i] = (res * i) % mod;
        res = jc[i];
    }
}
void solve()
{
    ans = 0;
    cin >> n;
    map<ll, ll> ma;
    if (n == 1)
    {
        cout << 0 << ' ' << 1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    sort(a + 1, a + 1 + n, cmp);
    f[0] = 0;
    f[n + 1] = 0;
    f[n] = 0;
    // for (int i = 1; i <= 100; i++)
    // {
    //     cout << jc[i] << ' ';
    // }
    for (int i = n; i >= 1; i--)
    {
        f[i] = f[i + 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ans += (n - i) * a[i] - f[i + 1];
    }
    ll p = 1;
    for (auto it : ma)
    {
        p = (p * jc[it.second]) % mod;
    }
    p = (2 * p) % mod;
    cout << ans << ' ' << p % mod << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    init();
    while (_--)
    {
        solve();
    }
    return 0;
}
