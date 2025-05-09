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
    ll s1, s2;
    cin >> s1 >> s2;
    if (s1 == 2 && s2 == 2)
    {
        cout << 1 << '\n';
        return;
    }
    ll p = __gcd(s1, s2);
    if (p < 2)
    {
        cout << 0 << '\n';
        return;
    }
    for (ll i = 2; i * i <= p; i++)
    {
        if (s1 % i == 0 && s2 % i == 0)
        {
            cout << (s1 / i) * (s2 / i) << '\n';
            return;
        }
    }
    cout << (s1 / p) * (s2 / p) << '\n';
    return;
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
