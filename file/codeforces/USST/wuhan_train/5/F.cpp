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
ll k;
ll ask(ll i, ll j, ll x)
{
    ll res;
    cout << "? " << i << ' ' << j << ' ' << x << endl;
    cin >> res;
    return res;
}
bool check(ll x)
{
    ll res = 0;
    ll p = 0;
    for (int i = n; i >= 1; i--)
    {
        while (p + 1 <= n)
        {
            bool t = ask(i, p + 1, x);
            if (t)
            {
                p++;
            }
            else
            {
                break;
            }
        }
        res += n - p;
    }
    // cout << res << endl;
    //  xiaoyu x的数量
    return res < k;
}
void solve()
{

    cin >> n >> k;
    ll l = 1, r = n * n;
    // 小于 mid 的数 是否小于等于k
    while (r - 1 != l)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << '!' << " " << r << endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}