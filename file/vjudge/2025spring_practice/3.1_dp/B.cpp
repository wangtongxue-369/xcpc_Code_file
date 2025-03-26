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
ll _ = 1, n, m, ans = 0, a[MAXN], f[20050];
void solve()
{
    ll v;
    cin >> v;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ans = 0;
    // 考虑到i物品 j容量时的最大容量
    for (int i = 1; i <= n; i++)
    {
        for (ll j = v; j >= 1; j--)
        {
            if (j - a[i] >= 0)
            {
                f[j] = max(f[j], f[j - a[i]] + a[i]);
            }
        }
    }
    cout << v - f[v] << '\n';
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
