#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    ll x;
    a[0] = 1;
    a[1] = 2;
    for (int i = 2; i <= 100100; i++)
    {
        a[i] = a[i - 1] * 2 % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        cout << a[x] << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
