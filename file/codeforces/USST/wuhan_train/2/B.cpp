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
ll _ = 1, n, m, ans = 0, f[MAXN];
map<ll, priority_queue<PII, vector<PII>, greater<PII>>> ve;
ll du[MAXN];
void solve()
{
    map<ll, ll> a;
    ll g;
    cin >> g;
    ll t, u;
    for (int i = 1; i <= g; i++)
    {
        cin >> t >> u;
        a[t] = u;
    }
    cin >> n;
    ll aj, bj;
    ll k, cj, dj;
    vector<vector<PII>> ve2(MAXN);
    queue<ll> q;
    for (ll i = 1; i <= n; i++)
    {
        cin >> m;
        for (ll j = 1; j <= m; j++)
        {
            cin >> aj >> bj;
            if (a[aj] >= bj)
            {
                continue;
            }
            du[i]++;
            ve[aj].emplace(bj, i);
        }
        if (du[i] == 0)
        {
            q.push(i);
        }
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> cj >> dj;
            ve2[i].push_back({cj, dj});
        }
    }
    ans = 0;
    while (!q.empty())
    {
        auto i = q.front();
        ans++;
        q.pop();
        for (auto [c, b] : ve2[i])
        {
            a[c] += b;
            while (!ve[c].empty() && ve[c].top().first <= a[c])
            {
                du[ve[c].top().second]--;
                if (du[ve[c].top().second] == 0)
                {
                    q.push(ve[c].top().second);
                }
                ve[c].pop();
            }
        }
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
