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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
ll cou(ll x)
{
    ll res = 1;
    for (ll i = 2; i * i <= x; i++)
    {
        int cnt = 0;
        while (x % i == 0)
        {
            cnt++;
            x /= i;
        }
        if (cnt > 0)
        {
            res *= (cnt + 1);
        }
    }
    if (x > 1)
    {
        res *= 2;
    }
    return res;
}
void solve()
{
    cin >> n;
    for (int i = 1;; i++)
    {
        ll a, b;
        if (i % 2 == 0)
        {
            a = i / 2;
            b = i + 1;
        }
        else
        {
            a = i;
            b = (i + 1) / 2;
        }
        if (cou(a) * cou(b) > n)
        {
            cout << i * (i + 1) / 2 << '\n';
            return;
        }
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
