#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a, b, k[MAXN]; // a[MAXN], f[MAXN];
vector<vector<ll>> ve(MAXN + 10);
vector<ll> dis(MAXN + 10, 1e9);
void solve()
{
    cin >> n >> a >> b;
    ll p = 0;
    dis[a] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        p = i + k[i];
        if (1 <= p && p <= n)
        {
            ve[i].push_back(p);
        }
        p = i - k[i];
        if (1 <= p && p <= n)
        {
            ve[i].push_back(p);
        }
    }
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, a});
    while (q.size())
    {
        auto [di, u] = q.top();
        q.pop();
        if (dis[u] < di)
        {
            continue;
        }
        for (auto it : ve[u])
        {
            if (dis[it] > di + 1)
            {
                dis[it] = di + 1;
                q.push({dis[it], it});
            }
        }
    }
    if (dis[b] == 1e9)
    {
        cout << -1 << '\n';
        return;
    }
    cout << dis[b] << '\n';
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
