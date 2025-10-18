/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
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
    vector<vector<ll>> ve(n + 10);
    vector<ll> du(n + 10);
    vector<array<ll, 4>> su;
    ll x, y, u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> x >> y;
        su.push_back({x, y, u, v});
        if (x >= y)
        {
            ve[v].push_back(u);
            du[u]++;
        }
        else
        {
            ve[u].push_back(v);
            du[v]++;
        }
    }
    // priority_queue<ll> q;
    // while (!q.empty())
    // {
    //     auto x = q.top();
    //     q.pop();
    //     for (auto it : ve[x]){
    //         if ()
    //     }
    // }
    queue<ll> q;
    for (int i = 1; i <= n; i++)
    {
        if (du[i] == 0)
        {
            q.push(i);
        }
    }
    vector<ll> vv;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        vv.push_back(x);
        for (auto it : ve[x])
        {
            du[it]--;
            if (du[it] == 0)
            {
                q.push(it);
            }
            // q.push(it);
        }
    }
    ll p = 1;
    map<ll, ll> ma;
    for (int i = 0; i < n; i++)
    {
        ma[vv[i]] = p;
        p++;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ma[i] << ' ';
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