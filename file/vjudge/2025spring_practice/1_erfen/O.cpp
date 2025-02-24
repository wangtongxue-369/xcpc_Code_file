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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN], c[MAXN], k[MAXN];
bool check(ll x, ll i)
{
    // ll de;
    // for (int i = 1; i <= n; i++)
    // {
    //     de = (b[i] - x) * (b[i] - x) - 4 * a[i] * (c[i]);
    //     if (de >= 0)
    //     {
    //         return 0;
    //     }
    // }
    // return 1;
    ll de = (b[i] - x) * (b[i] - x) - 4 * a[i] * (c[i]);
    if (de >= 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    sort(k + 1, k + 1 + n);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    bool flag = 0;
    for (int i = 1; i <= m; i++)
    {
        ll l = 1, r = n;
        flag = 0;
        while (l < r)
        {
            ll mid = (l + r) >> 1;
            if (k[mid] >= b[i])
            {

                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (!flag)
        {
            if (check(k[l], i))
            {
                cout << "YES\n";
                cout << k[l] << '\n';
            }
            else
            {
                l--;
                if (l >= 1 && check(k[l], i))
                {
                    cout << "YES\n";
                    cout << k[l] << '\n';
                }
                else
                {
                    cout << "NO\n";
                }
            }
        }
    }

    // cout << l << '\n';
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
