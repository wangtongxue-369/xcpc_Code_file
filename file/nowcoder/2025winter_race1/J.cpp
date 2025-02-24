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
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    ans = 0;
    for (auto [x, y] : ma)
    {
        for (ll i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                ll j = x + i;
                if (ma.count(j))
                {
                    if ((j ^ x) == __gcd(j, x))
                    {
                        ans += y * ma[j];
                    }
                }
                j = x + x / i;
                if (ma.count(j) && i * i != x)
                {
                    if ((j ^ x) == __gcd(j, x))
                    {
                        ans += y * ma[j];
                    }
                }
            }
        }
    }
    cout << ans << '\n';
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
