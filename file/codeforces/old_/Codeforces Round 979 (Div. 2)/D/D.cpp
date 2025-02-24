#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, q, ans = 0, a[MAXN], f[MAXN], g[MAXN];
string s;
ll check(ll i)
{
    if (s[i] == 'R' || s[i + 1] == 'L')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
ll check2(ll i)
{
    if (g[i] == 1 && f[i] == 0)
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
    cin >> n >> q;
    ll maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        if (i < maxn)
        {
            g[i] = 1;
        }
        else
        {
            g[i] = 0;
        }
    }
    cin >> s;
    ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        f[i + 1] = check(i);
    }
    for (int i = 1; i < n; i++)
    {
        ans += check2(i);
    }
    while (q--)
    {
        ll x;
        cin >> x;
        if (s[x - 1] == 'L')
        {
            s[x - 1] = 'R';
        }
        else
        {
            s[x - 1] = 'L';
        }
        if (x - 1 > 0)
        {
            ans -= check2(x - 1);
        }
        if (x <= n - 1)
        {
            ans -= check2(x);
        }
        if (x - 1 > 0)
        {
            f[x - 1] = check(x - 2);
        }
        if (x <= n - 1)
        {
            f[x] = check(x - 1);
        }
        if (x - 1 > 0)
        {
            ans += check2(x - 1);
        }
        if (x <= n - 1)
        {
            ans += check2(x);
        }
        if (ans == 0)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
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
