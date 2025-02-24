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
bool check(ll x)
{
    // 跳跃距离越小，要移走的石头越少
    // 跳跃距离越大，可以移走的石头越多
    ll sum = 0;
    ll s = 0;
    ll p = 0;
    for (int i = 0; i < n; i++)
    {
        s = i;
        while (a[i + 1] - a[s] < x && i < n)
        {
            sum++;
            i++;
        }
    }
    if (sum <= m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void solve()
{
    ll len;
    cin >> len >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    n++;
    a[0] = 0, a[n] = len;
    ll l = 1, r = len;
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l << '\n';
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
