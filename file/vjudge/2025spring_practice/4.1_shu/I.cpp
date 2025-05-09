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
    ll u;
    cin >> n;
    vector<vector<ll>> ve(n + 10);
    vector<ll> w(n + 10);
    w[0] = 2200;
    for (ll i = 1; i <= n; i++)
    {
        cin >> u >> w[i];
        ve[u].push_back(i);
    }
    vector<ll> re;
    ll sumy = 0;
    function<void(ll x)> dfs = [&](ll x)
    {
        if (ve[x].size() == 0)
        {
            sumy += w[x];
            return;
        }
        for (auto it : ve[x])
        {
            dfs(it);
        }
        re.push_back(w[x]);
    };
    // re.push_back(2200);
    dfs(0);
    vector<ll> ne;
    function<ll(ll x)> dfs1 = [&](ll x)
    {
        ll res = 0;
        if (ve[x].size() == 0)
        {
            return w[x];
        }
        for (auto it : ve[x])
        {
            res += dfs1(it);
        }
        ne.push_back(res);
        return res;
    };
    ne.push_back(dfs1(0));
    sort(re.begin(), re.end());
    sort(ne.begin(), ne.end());

    // cout << sumy << '\n';
    // cout << re.size() << ' ' << ne.size() << '\n';
    // for (auto it : re)
    // {
    //     cout << it << ' ';
    // }
    // cout << '\n';
    // for (auto it : ne)
    // {
    //     cout << it << ' ';
    // }
    // cout << '\n';

    if (sumy > 2200)
    {
        cout << "NO\n";
        return;
    }
    for (ll i = re.size() - 1; i >= 0; i--)
    {
        if (ne[i] <= re[i])
        {
            continue;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}