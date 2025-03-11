#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 100005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, u[MAXN], v[MAXN], w[MAXN];
void solve()
{
    cin >> n;
    cin >> u[1] >> v[1] >> w[1];
    ll x1, x2, x3, x4, x5, x6;
    if (n == 1)
    {
        x1 = (w[1] - v[1]) / u[1];
        x2 = (u[1] - w[1]) / v[1];
        x3 = (v[1] - u[1]) / w[1];
        x4 = (w[1] - u[1]) / v[1];
        x5 = (u[1] - v[1]) / w[1];
        x6 = (v[1] - w[1]) / u[1];
        map<ll, ll> ma;
        ma[x1]++, ma[x2]++, ma[x3]++, ma[x4]++, ma[x5]++, ma[x6]++;
        for (auto it : ma)
        {
            if (it.first >= 0)
            {
                cout << it.first << '\n';
                return;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
    ll x = (w[1] - v[1]) / u[1];
    // cout << x << '\n';
    bool flag = 1;

    for (int i = 2; i <= n; i++)
    {
        x1 = (w[i] - v[i]) / u[i];
        x2 = (u[i] - w[i]) / v[i];
        x3 = (v[i] - u[i]) / w[i];
        x4 = (w[i] - u[i]) / v[i];
        x5 = (u[i] - v[i]) / w[i];
        x6 = (v[i] - w[i]) / u[i];
        if (!(x1 == x || x2 == x || x3 == x || x4 == x || x5 == x || x6 == x || x < 0))
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << x << '\n';
        return;
    }
    flag = 1;
    x = (u[1] - w[1]) / v[1];
    // cout << x << '\n';
    for (int i = 2; i <= n; i++)
    {
        x1 = (w[i] - v[i]) / u[i];
        x2 = (u[i] - w[i]) / v[i];
        x3 = (v[i] - u[i]) / w[i];
        x4 = (w[i] - u[i]) / v[i];
        x5 = (u[i] - v[i]) / w[i];
        x6 = (v[i] - w[i]) / u[i];
        if (!(x1 == x || x2 == x || x3 == x || x4 == x || x5 == x || x6 == x || x < 0))
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << x << '\n';
        return;
    }
    flag = 1;
    x = (v[1] - u[1]) / w[1];
    // cout << x << '\n';
    for (int i = 2; i <= n; i++)
    {
        x1 = (w[i] - v[i]) / u[i];
        x2 = (u[i] - w[i]) / v[i];
        x3 = (v[i] - u[i]) / w[i];
        x4 = (w[i] - u[i]) / v[i];
        x5 = (u[i] - v[i]) / w[i];
        x6 = (v[i] - w[i]) / u[i];
        if (!(x1 == x || x2 == x || x3 == x || x4 == x || x5 == x || x6 == x || x < 0))
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << x << '\n';
        return;
    }
    flag = 1;
    x = (w[1] - u[1]) / v[1];
    for (int i = 2; i <= n; i++)
    {
        x1 = (w[i] - v[i]) / u[i];
        x2 = (u[i] - w[i]) / v[i];
        x3 = (v[i] - u[i]) / w[i];
        x4 = (w[i] - u[i]) / v[i];
        x5 = (u[i] - v[i]) / w[i];
        x6 = (v[i] - w[i]) / u[i];
        if (!(x1 == x || x2 == x || x3 == x || x4 == x || x5 == x || x6 == x || x < 0))
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << x << '\n';
        return;
    }
    flag = 1;
    x = (u[1] - v[1]) / w[1];
    for (int i = 2; i <= n; i++)
    {
        x1 = (w[i] - v[i]) / u[i];
        x2 = (u[i] - w[i]) / v[i];
        x3 = (v[i] - u[i]) / w[i];
        x4 = (w[i] - u[i]) / v[i];
        x5 = (u[i] - v[i]) / w[i];
        x6 = (v[i] - w[i]) / u[i];
        if (!(x1 == x || x2 == x || x3 == x || x4 == x || x5 == x || x6 == x || x < 0))
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << x << '\n';
        return;
    }
    flag = 1;
    x = (v[1] - w[1]) / u[1];
    for (int i = 2; i <= n; i++)
    {
        x1 = (w[i] - v[i]) / u[i];
        x2 = (u[i] - w[i]) / v[i];
        x3 = (v[i] - u[i]) / w[i];
        x4 = (w[i] - u[i]) / v[i];
        x5 = (u[i] - v[i]) / w[i];
        x6 = (v[i] - w[i]) / u[i];
        if (!(x1 == x || x2 == x || x3 == x || x4 == x || x5 == x || x6 == x || x < 0))
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << x << '\n';
        return;
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
