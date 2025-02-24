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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    cin >> n >> m;
    vector<vector<ll>> a(n + 10, vector<ll>(m + 10, 0));

    ll minn = 1e10, maxn = 0;
    vector<ll> p(m + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            minn = min(minn, a[i][j]);
            maxn = max(maxn, a[i][j]);
            p[j] = max(p[j], a[i][j]);
        }
    }
    function<bool(ll x)> check = [&](ll x)
    {
        // vector<ll> ve(n+10,0);
        //  除去当前这一行，每个人可以得到的最小的快乐值
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum = 0;
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] >= x)
                {
                    sum++;
                }
                if (sum >= 2)
                {
                    return 1;
                }
            }
        }
        return 0;
    };
    ll ss = 1e10;
    for (int i = 1; i <= m; i++)
    {
        ss = min(ss, p[i]);
    }
    ll l = minn, r = maxn;
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (mid <= ss && check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l << '\n';
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
