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
void solve()
{
    map<ll, ll> ma;
    cin >> n;
    ll x;
    vector<ll> a(n + 10), f(n + 10, INF);
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x < n)
        {
            a[x]++;
        }
        // cin >> a[i];
        // ma[a[i]]++;
    }
    ll p = 0;
    while (a[p])
        p++;
    f[p] = 0;
    for (int i = p; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            f[j] = min(f[j], f[i] + a[j] * i);
        }
    }
    cout << f[0] - p << '\n';
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