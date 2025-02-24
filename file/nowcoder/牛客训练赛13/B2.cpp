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
ll _ = 1, n, m, ans = 0, k; // a[MAXN], f[MAXN];
inline ll read()
{
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}
vector<ll> a;
vector<ll> pra;
ll get(ll x, ll i)
{
    // x 长度
    //  a[i+x-1]-a[i] 实际
    //
    if ((a[i + x - 1] - a[i]) - x > k)
    {
        return 0;
    }
    return x + k - ((a[i + x - 1] - a[i]) - x);
}
bool check(ll len, ll i)
{
    auto it = lower_bound(pra.begin(), pra.end(), pra[i] + k);
    if (it == pra.end())
    {
    }
    ll f = pra[i + len - 1] - pra[i];
    if (f > k)
    {
        return 0;
    }
    if ()
}
void solve()
{
    n = read(), m = read(), k = read();
    a.clear();
    pra.clear();
    for (int i = 1; i <= n; i++)
    {
        ll x = read();
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    n = unique(a.begin(), a.end()) - a.begin();
    pra.push_back(0ll);
    for (int i = 1; i < n; i++)
    {
        pra.push_back(pra[i - 1] + a[i] - a[i - 1] - 1);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << pra[i] << ' ';
    // }
    // cout << '\n';
    for (int i = 0; i < n; i++)
    {
        ll l = 1, r = (n - i);
        while (l < r)
        {
            ll mid = (l + r + 1) >> 1;
            if (check(mid, i))
                l = mid;
            else
                r = mid - 1;
        }
        ans = max(ans, l);
    }
    cout << ans << '\n';
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
