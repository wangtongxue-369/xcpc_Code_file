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
    a[1] = 1;
    ll x, p;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            cin >> p;
            a[i] += a[p];
            a[i] %= mod;
        }
    }
    cout << a[n] % mod << '\n';
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