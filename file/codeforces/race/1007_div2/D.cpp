#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 200005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll dfs(ll l)
{
    if (l <= n)
    {
        return a[l] ^ a[l - 1];
    }
    if (l / 2 <= n)
    {
        return a[l / 2];
    }
    ll res = a[n];
    if ((l / 2) % 2 == 0)
    {
        res ^= dfs(l / 2);
    }
    if (n % 2 == 0)
    {
        res ^= dfs(n + 1);
    }
    return res;
}
void solve()
{
    ll l, r;
    cin >> n >> l >> r;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
        // sum ^= a[i];
    }
    cout << dfs(l) << '\n';
}
// n个1  m个0
// (n%2)^(m%2)
// 统计范围内0的数量  答案就是(sum%2)^((n-sum)%2)
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