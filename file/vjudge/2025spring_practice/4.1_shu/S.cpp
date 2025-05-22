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
ll _ = 1, n, m, ans = 0, a[MAXN], p[MAXN], dep[MAXN], num[MAXN], vis[MAXN];
bool check(ll i)
{
    if (dep[i] == m)
    {
        return 1;
    }
    if (num[i] + 1 > n || num[i] + (1 << (m - dep[i])) > n)
    {
        return 0;
    }
    if (i != a[num[i] + 1] / 2 || i != a[num[i] + (1 << (m - dep[i]))] / 2)
    {
        return 0;
    }
    return 1;
}
void solve()
{
    ll q;
    ll cnt = 0;
    cin >> n >> q;
    for (ll i = 1; i < n; i++)
    {
        cin >> p[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        dep[i] = dep[i / 2] + 1;
    }
    for (int i = 1; i <= 16; i++)
    {
        if (n == ((1ll << i) - 1))
        {
            m = i;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!check(i))
        {
            cnt++;
            vis[i] = 1;
        }
    }
    ll x, y;
    while (q--)
    {
        cin >> x >> y;
        swap(num[a[x]], num[a[y]]);
        swap(a[x], a[y]);
        if (dep[a[x]] < m)
        {
            if (check(a[x]))
            {
                if (vis[a[x]])
                {
                    cnt--;
                }
                vis[a[x]] = 0;
            }
            else
            {
                if (!vis[a[x]])
                {
                    cnt++;
                }
                vis[a[x]] = 1;
            }
        }
        if (dep[a[y]] < m)
        {
            if (check(a[y]))
            {
                if (vis[a[y]])
                {
                    cnt--;
                }
                vis[a[y]] = 0;
            }
            else
            {
                if (!vis[a[y]])
                {
                    cnt++;
                }
                vis[a[y]] = 1;
            }
        }
        if (a[x] != 1)
        {
            if (check(a[x] / 2))
            {
                if (vis[a[x] / 2])
                {
                    cnt--;
                }
                vis[a[x] / 2] = 0;
            }
            else
            {
                if (!vis[a[x] / 2])
                {
                    cnt++;
                }
                vis[a[x] / 2] = 1;
            }
        }
        if (a[y] != 1)
        {
            if (check(a[y] / 2))
            {
                if (vis[a[y] / 2])
                {
                    cnt--;
                }
                vis[a[y] / 2] = 0;
            }
            else
            {
                if (!vis[a[y] / 2])
                {
                    cnt++;
                }
                vis[a[y] / 2] = 1;
            }
        }
        if (cnt == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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