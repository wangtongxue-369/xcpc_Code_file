#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ull unsigned long long
#define int long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = (1 << 18);
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll tr[MAXN * 2];
ll lowbit(ll x)
{
    return (x & (-x));
}
void add(ll x, ll v)
{
    while (x <= n)
    {
        tr[x] += v;
        x += lowbit(x);
    }
}
ll sum(ll x)
{
    ll res = 0;
    while (x)
    {
        res += tr[x];
        x -= lowbit(x);
    }
    return res;
}
void solve()
{
    ll ans = 0;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        ans += sum(n) - sum(v[i] + 1);
        add(v[i] + 1, 1);
    }
    int summ = 0;
    for (int i = 0; (1ll << i) < n; i++)
    {
        ll res = 0;
        for (int j = 1; j <= n; j++)
        {
            tr[j] = 0;
        }
        for (int j = 1; j <= n; j++)
        {

            res += sum(n) - sum((v[j] ^ (1ll << i)) + 1);
            add(((v[j] ^ (1ll << i)) + 1), 1);
        }
        if (res < ans)
        {
            summ += ans - res;
        }
    }
    cout << min(ans, summ);
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