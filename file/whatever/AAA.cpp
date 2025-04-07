
#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = (j); i < (k); ++i)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct node
{
    int dis, v, u;
    bool operator>(const node &a) const
    {
        return dis > a.dis || dis == a.dis && v < a.v;
    }
};
struct fun
{
    int dis{0x3f3f3f3f}, sum{0}, cnt{0};
    vector<int> c;
};

void solve()
{
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<pii> e[n];
    vector<int> a(n);
    for (auto &ai : a)
        cin >> ai;
    rep(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].pb({v, w});
        e[v].pb({u, w});
    }
    vector<fun> f(n);
    priority_queue<node, vector<node>, greater<node>> q;
    f[s] = {0, a[s], 1, {s}};
    q.push({0, a[s], s});
    while (!q.empty())
    {
        auto [dis, v, u] = q.top();
        q.pop();
        if (f[u].dis < dis)
        {
            continue;
        }
        for (auto [v, w] : e[u])
        {
            if (f[v].dis == f[u].dis + w)
            {
                if (f[v].sum < f[u].sum + a[v])
                {
                    f[v].c = f[u].c;
                    f[v].c.pb(v);
                }
                f[v].sum = max(f[v].sum, f[u].sum + a[v]);
                f[v].cnt += f[u].cnt;
                // q.push({f[v].dis, f[v].sum, v});
            }
            else if (f[v].dis > f[u].dis + w)
            {
                f[v] = f[u];
                f[v].dis += w;
                f[v].sum += a[v];
                f[v].c.pb(v);
                q.push({f[v].dis, f[v].sum, v});
            }
        }
    }
    cout << f[d].cnt << ' ' << f[d].sum << endl;
    rep(i, 0, f[d].c.size())
    {
        if (i)
            cout << ' ';
        cout << f[d].c[i];
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t{1};
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}