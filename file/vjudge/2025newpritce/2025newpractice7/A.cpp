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
    ll suma = 0, sumb = 0;
    for (int i = 1; i <= 9; i++)
    {
        ll x;
        cin >> x;
        suma += x;
    }
    for (int i = 1; i <= 8; i++)
    {
        ll x;
        cin >> x;
        sumb += x;
    }
    cout << max(suma - sumb + 1, 0ll) << '\n';
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
