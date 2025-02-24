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
ll _ = 1, t, n, m, ans = 0; // a[MAXN], f[MAXN];
char a[350][350];
ll vis[310][310];
const int tx[4] = {1, -1, 0, 0};
const int ty[4] = {0, 0, 1, -1};
vector<PII> ca;
ll bfs(ll st, ll en)
{
    memset(vis, 0, sizeof(vis));
    queue<PII> q;
    q.push(ca[st]);
    vis[ca[st].first][ca[st].second] = 1;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            ll xx = x + tx[i];
            ll yy = y + ty[i];
            if (1 <= xx && xx <= n && 1 <= yy && yy <= m && a[xx][yy] != '#' && vis[xx][yy] == 0)
            {
                if (xx == ca[en].first && yy == ca[en].second)
                {
                    return vis[x][y];
                }
                vis[xx][yy] = vis[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
    return 1e18;
}
void solve()
{
    cin >> n >> m >> t;
    PII st, en;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S')
            {
                st.first = i, st.second = j;
            }
            else if (a[i][j] == 'G')
            {
                en.first = i, en.second = j;
            }
            else if (a[i][j] == 'o')
            {
                ca.emplace_back(i, j);
            }
        }
    }
    ca.emplace_back(st);
    ca.emplace_back(en);
    ll siz = ca.size();
    vector<vector<ll>> dis(siz + 10, vector<ll>(siz + 10, 0));
    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {
            dis[i][j] = dis[j][i] = bfs(i, j);
        }
    }
    vector<vector<ll>> dp(25, vector<ll>((1 << 20) + 5, 1e18));
    if (dis[siz - 1][siz - 2] > t)
    {
        cout << -1 << '\n';
        return;
    }
    dp[siz - 2][(1ll << (siz - 2))] = 0;
    for (int i = (1 << (siz - 2)); i < (1 << siz); i++)
    {
        if (!((i >> (siz - 2)) & 1))
            continue;
        for (int j = 0; j < siz; j++)
        {
            if (!((i >> j) & 1))
                continue;
            for (int k = 0; k < siz; k++)
            {
                dp[k][i | (1 << k)] = min(dp[k][i | (1 << k)], dp[j][i] + dis[j][k]);
            }
        }
    }
    ans = 0;
    for (int i = (1 << (siz - 2)); i < (1 << siz); i++)
    {
        if ((!((i >> (siz - 2)) & 1)) || (!((i >> (siz - 1)) & 1)) || (dp[siz - 1][i] > t))
            continue;
        ll sum = 0;
        for (int j = 0; j < siz - 2; j++)
        {
            if ((i >> j) & 1)
                sum++;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
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
