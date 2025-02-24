#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    ll k, q, x;
    cin >> n >> k >> q;
    map<ll, vector<ll>> ma;

    for (int j = 1; j <= k; j++)
    {
        cin >> x;
        ma[j].push_back(x);
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            cin >> x;
            x |= ma[j][ma[j].size() - 1];
            ma[j].push_back(x);
        }
    }
    while (q--)
    {
        // cout << q << '\n';
        bool flag = 1;
        cin >> m;
        char op;
        ll r1, c;
        vector<pair<ll, ll>> l, r;
        for (ll i = 1; i <= m; i++)
        {
            cin >> r1 >> op >> c;
            if (op == '>')
            {
                l.push_back({r1, c});
            }
            else
            {
                r.push_back({r1, c});
            }
        }
        ll ansl = 0; // ansr = 1e9;
        for (auto it : l)
        {
            ll r1 = it.first, c = it.second;
            ansl = max(ansl, upper_bound(ma[r1].begin(), ma[r1].end(), c) - ma[r1].begin());
        }
        if (ansl >= n)
        {
            cout << "-1" << '\n';
            continue;
        }
        for (auto it : r)
        {
            ll r1 = it.first, c = it.second;
            if (ma[r1][ansl] >= c)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout << ansl + 1 << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
