#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    map<ll, ll> ma;
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        ma[x]++;
    }
    ans = 0;
    for (auto it : ma)
    {
        ll maxn = 0;
        ll next = it.first + 1;
        ll b = 0;
        ll a = min(k / it.first, it.second);
        if (ma.count(next))
        {
            b = ma[next];
        }
        for (int i = 0; i <= a; i++)
        {
            ll j = (k - i * it.first) / next;
            j = min(j, b);
            maxn = max(maxn, i * it.first + j * next);
        }
        ans = max(ans, maxn);
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
