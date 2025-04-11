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
    }
    ll res = 0;
    ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        if (!ma.contains(a[i]))
        {
            f[i] = f[i - 1] + 1;
            ma[a[i]] = i;
        }
        else
        {
            f[i] = min(f[i - 1] + 1, f[ma[a[i]] - 1]);
            if (f[i - 1] < f[ma[a[i]] - 1])
            {
                ma[a[i]] = i;
            }
        }
    }
    cout << n - f[n] << '\n';
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