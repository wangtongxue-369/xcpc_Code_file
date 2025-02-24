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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN][40];
ll k;
ll l = 1, r = n;
ll lef;
bool check(ll x)
{
    ll sum = 0;
    ll p;
    for (int i = 0; i <= 30; i++)
    {
        p = f[x][i] - f[lef - 1][i];
        if (p == (x - lef + 1) && p != 0)
        {
            sum += (1ll << i);
        }
        // if (x == 2)
        // {
        //     cout << i << '\n';
        //     cout << p << ' ' << r - lef + 1 << ' ' << sum << '\n';
        // }
    }
    // if (x == 2)
    // {
    //     cout << sum << '\n';
    // }

    if (sum >= k)
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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 0; j <= 30; j++)
        {
            f[i][j] = 0;
            if (((1ll << j) & a[i]))
            {
                f[i][j] = f[i - 1][j] + 1;
            }
            else
            {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    // for (int i = 0; i <= 10; i++)
    // {
    //     cout << f[2][i];
    // }
    // cout << '\n';
    // for (int i = 0; i <= 10; i++)
    // {
    //     cout << f[1][i];
    // }
    l = 1;
    lef = 1;
    k = 15;
    // cout << check(2) << '\n';
    ll q;
    cin >> q;
    while (q--)
    {
        r = n;
        cin >> lef >> k;

        if (a[lef] < k)
        {
            cout << -1 << ' ';
            continue;
        }
        l = lef;
        r = n;
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
        cout << l << ' ';
    }
    cout << '\n';
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
