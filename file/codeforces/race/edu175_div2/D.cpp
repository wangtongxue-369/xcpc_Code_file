#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
void solve()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> dep(n + 10, 0);

    ll mdep = 0;
    for (int i = 2; i <= n; i++)
    {
        dep[i] = dep[a[i]] + 1;
        mdep = max(mdep, dep[i]);
    }
    vector<vector<ll>> ve(mdep + 10);
    vector<ll> f(n + 10, 0);
    vector<ll> presum(mdep + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        ve[dep[i]].push_back(i);
    }
    presum[0] = 1;
    f[1] = 1;
    for (int i = 1; i <= mdep; i++)
    {
        ll sum = 0;
        if (i == 1)
        {
            for (auto it : ve[i])
            {
                f[it] = presum[i - 1];
                sum = (sum + f[it]) % mod;
            }
        }
        else
        {
            for (auto it : ve[i])
            {
                f[it] = (presum[i - 1] - f[a[it]] + mod) % mod;
                sum = (sum + f[it]) % mod;
            }
        }
        presum[i] = sum;
    }
    ans = 1;
    for (int i = 1; i <= mdep; i++)
    {
        ans = (ans + presum[i]) % mod;
    }
    cout << ans << '\n';
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
