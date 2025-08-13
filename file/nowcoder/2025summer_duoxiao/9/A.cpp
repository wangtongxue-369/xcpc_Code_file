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
void dfs(int u, int fa, const vector<vector<ll>> &ve, vector<ll> &h, vector<ll> &si)
{
    si[u] = 1;
    ll maxh = 0;
    bool is_leaf = true;
    for (ll v : ve[u])
    {
        if (v == fa)
            continue;
        is_leaf = false;
        dfs(v, u, ve, h, si);
        si[u] += si[v];
        maxh = max(maxh, h[v]);
    }
    h[u] = is_leaf ? 1 : maxh + 1;
}
void solve()
{
    cin >> n;
    vector<vector<ll>> ve(n + 10);
    vector<ll> h(n + 1), cnt(n + 1), si(n + 10), l(n + 10), r(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        if (l[i])
        {
            ve[i].push_back(l[i]);
        }
        if (r[i])
        {
            ve[i].push_back(r[i]);
        }
    }
    dfs(1, 0, ve, h, si);
    vector<array<ll, 30>> dp;
    vector<ll> need(n + 10, 0);
    stack<ll> st;
    queue<ll> q;
    vector<ll> vis(n + 10);
    q.push(1);
    while (!q.empty())
    {
        st.push(q.front());
        ll t = q.front();
        q.pop();
        if (vis[t] == 0)
        {
            vis[t] = 1;
            if (l[t])
                st.push(l[t]);
            if (r[t])
                st.push(r[t]);
        }
    }
    while (!st.empty())
    {
        ll u = st.top();
        st.pop();
        dp[u][0] = si[u];
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