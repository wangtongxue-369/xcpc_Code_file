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
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
void solve()
{
    ll m, k;
    cin >> n >> m >> k;
    vector<bool> busy(n + 10, 0);
    ll x;
    for (int i = 1; i <= k; i++)
    {
        cin >> x;
        busy[x] = 1;
    }
    vector<vector<ll>> ve(n + 10);
    ll u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    vector<bool> f(n + 10, 0);
    map<ll, vector<ll>> ma;
    vector<string> s;
    queue<PII> q;
    bool flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (busy[i] == 0)
        {
            flag = 0;
            f[i] = 1;
            q.push({i, 0});
            break;
        }
    }
    if (flag)
    {
        cout << "No\n";
        return;
    }
    while (!q.empty())
    {
        auto [i, fa] = q.front();
        q.pop();
        if (busy[i] == 1)
        {
            continue;
        }
        string s1;
        s1 += to_string(i);
        s1 += ' ';
        vector<ll> an;
        for (auto it : ve[i])
        {
            if (it == fa || f[it] == 1)
            {
                continue;
            }
            an.push_back(it);
            if (busy[it] == 1)
            {
                f[it] = 1;
                continue;
            }
            f[it] = 1;
            q.push({it, i});
        }
        if (an.size() == 0)
        {
            continue;
        }
        x = an.size();
        s1 += to_string(x);
        for (auto it : an)
        {
            s1 += " ";
            s1 += to_string(it);
            // s1 += (char)(it + '0');
        }
        s.push_back(s1);
    }
    ll add = accumulate(f.begin(), f.end(), 0ll);
    if (add != n)
    {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes\n";
    cout << s.size() << '\n';
    for (auto it : s)
    {
        cout << it << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
