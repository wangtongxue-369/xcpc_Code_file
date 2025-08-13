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
    map<ll, ll> ma;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    ans = 0;
    ll res = 0;
    ll can = 0;
    for (auto it : ma)
    {
        if (it.second == 1)
        {
            can++;
        }
        if (it.second == 2)
        {
            continue;
        }
    }
    ll p = 0;
    for (auto it : ma)
    {
        if (it.second > 2)
        {
            p = it.second - 2;
            ll t = min(can, p);
            ans += t;
            can -= t;
            p -= t;
            ans += p;
        }
    }
    if (can != 0)
    {
        ans += can / 2;
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