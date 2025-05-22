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
    cin >> n;
    ll x, y;
    vector<vector<ll>> ve(n + 10);
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    ll minn = 1e18, p = 0;
    map<ll, vector<ll>> ma;
    function<ll(ll x, ll fa)> dfs = [&](ll x, ll fa)
    {
        ll maxn = 0;
        ll sum = 1; // 当前节点自身也算一个
        for (auto it : ve[x])
        {
            if (it == fa)
            {
                continue;
            }
            ll tm = dfs(it, x);
            sum += tm;
            maxn = max(maxn, tm);
        }
        maxn = max(maxn, n - sum);
        ma[maxn].push_back(x);
        if (maxn < minn)
        {
            p = x;
            minn = maxn;
        }
        return sum; // 返回当前子树的大小
    };
    dfs(1, -1);
    for (auto it : ma[minn])
    {
        // cout << it << ' ';
    }
    // cout << '\n';
    if (ma[minn].size() == 1)
    {
        if (!ve[p].empty()) // 确保ve[p]不为空
        {
            cout << p << ' ' << ve[p][0] << '\n';
            cout << p << ' ' << ve[p][0] << '\n';
        }
    }
    else
    {
        ll y = ma[minn][0], x = ma[minn][1];
        ll tmp = 0;
        for (auto it : ve[y])
        {
            if (it != x)
            {
                tmp = it;
                break;
            }
        }
        cout << tmp << ' ' << y << '\n';
        cout << tmp << ' ' << x << '\n';
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