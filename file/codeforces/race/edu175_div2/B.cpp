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
    ll x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'L')
        {
            a[i] = a[i - 1] + 1;
        }
        else
        {
            a[i] = a[i - 1] - 1;
        }
        if (ma.contains(a[i]))
        {
        }
        else
        {
            ma[a[i]] = i;
        }
    }
    if (!ma.contains(x))
    {
        cout << 0 << '\n';
        return;
    }
    ll p1 = ma[x];
    if (k < p1)
    {
        cout << 0 << '\n';
        return;
    }
    if (k == p1)
    {
        cout << 1 << '\n';
        return;
    }
    ans = 1;
    k -= p1;
    if (ma.contains(0))
    {
        ans += k / ma[0];
        cout << ans << '\n';
        return;
    }
    ll p = a[n];
    ll cs = n;
    if (ma.contains(-1 * p))
    {
        cs += ma[-1 * p];
        ans += k / cs;
        cout << ans << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
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
