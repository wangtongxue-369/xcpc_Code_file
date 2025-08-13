#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000050;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll gcd1(ll s1, ll s2)
{
    ll t;
    while (s2 > 0)
    {
        t = s1 % s2;
        s1 = s2;
        s2 = t;
    }
    return s1;
}
ll gcd2(ll s1, ll s2)
{
    if (s2 > 0)
    {
        return gcd2(s2, s1 % s2);
    }
    return s1;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        if (gcd2(a[i - 1], a[i]) == 1)
        {
            ans++;
        }
    }
    cout << ans << '\n';
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