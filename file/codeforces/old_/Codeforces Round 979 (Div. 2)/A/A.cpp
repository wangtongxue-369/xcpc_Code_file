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
    ll maxn = 0, minn = 1e10;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    cout << (maxn - minn) * (n - 1) << '\n';
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
