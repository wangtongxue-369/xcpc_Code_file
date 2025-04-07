#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
vector<vector<PII>> ve(MAXN);
ll dis[MAXN], rs[MAXN], ts[MAXN], road[MAXN];
ll vis[MAXN];
void solve()
{
    memset(dis, INF, sizeof(dis));
    memset(road, -1, sizeof(road));
    ll s, d;
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n; i++)
    { // 从 0 开始
        cin >> a[i];
    }
    ll x, y, l;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> l;
        // road[y] = x;
        ve[x].push_back({y, l});
        ve[y].push_back({x, l});
    }
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s});
    dis[s] = 0;
    rs[s] = a[s];
    ts[s] = 1;
    while (!q.empty())
    {
        auto [di, u] = q.top();
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        // if (dis[u] < di)
        // {
        //     continue;
        // }
        for (auto [v, w] : ve[u])
        {
            if (dis[v] > di + w)
            {
                dis[v] = di + w;
                ts[v] = ts[u];
                rs[v] = rs[u] + a[v];
                road[v] = u;
                q.push({dis[v], v});
            }
            else if (dis[v] == di + w)
            {
                ts[v] += ts[u];
                if (rs[u] + a[v] > rs[v])
                {
                    rs[v] = rs[u] + a[v];
                    road[v] = u;
                }
            }
        }
    }
    stack<ll> st;
    st.push(d);
    for (int i = road[d]; i != -1; i = road[i])
    {
        st.push(i);
    }
    cout << ts[d] << ' ' << rs[d] << '\n';
    while (st.size())
    {
        cout << st.top();
        if (st.size() != 1)
        {
            cout << " ";
        }
        st.pop();
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
