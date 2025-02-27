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
string s;
ll k;
bool check(ll x)
{
    ll cnt = 0;
    ll i = 1;
    for (int i = 1; i <= n;)
    {
        if (s[i] == 'R')
        {
            if (a[i] > x)
            {
                i++;
                continue;
            }
        }
        ll sum = 0;
        bool flag = 0;
        while (i <= n && (s[i] != 'R' || a[i] <= x))
        {
            if (s[i] == 'B' && a[i] > x && flag == 0)
            {
                cnt++;
                flag = 1;
            }
            i++;
        }
    }
    if (cnt <= k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (s[i] == 'R')
    //     {
    //         continue;
    //     }
    //     cout << i << '\n';
    //     cnt++;
    //     ll j;
    //     for (j = i; j <= n; j++)
    //     {
    //         if (a[j] > x)
    //         {
    //             continue;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //         // if (s[j] == 'B')
    //         // {
    //         //     continue;
    //         // }
    //         // if (s[j] == 'R' && a[j] <= x)
    //         // {
    //         //     continue;
    //         // }
    //         // else
    //         // {
    //         //     i = j;
    //         //     break;
    //         // }
    //     }
    //     i = j;
    // }
    // cout << x << ' ' << cnt << '\n';
    // if (cnt > k)
    // {
    //     return 0;
    // }
    // else
    // {
    //     return 1;
    // }
}
void solve()
{

    cin >> n >> k;
    cin >> s;
    s = ' ' + s;
    ll r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    ll l = 0;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << '\n';
    // ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (s[i] == 'R')
    //     {
    //         continue;
    //     }
    //     for (int j = i; j <= n; j++)
    //     {
    //         if (s[j] == 'B')
    //         {
    //             continue;
    //         }
    //         if (s[j] == 'R' && a[j] <= l)
    //         {
    //             ans = max(ans, a[j]);
    //             continue;
    //         }
    //         else
    //         {
    //             i = j - 1;
    //             break;
    //         }
    //     }
    // }
    // cout << ans << '\n';
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
