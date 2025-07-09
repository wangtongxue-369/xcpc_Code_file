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
ll _ = 1, n, m, ans = 0, a[MAXN];
bool isTangent(const array<ll, 3> &a, const array<ll, 3> &b)
{
    ll dx = a[0] - b[0];
    ll dy = a[1] - b[1];
    ll dist_sq = dx * dx + dy * dy;

    ll r_sum = a[2] + b[2];
    ll r_diff = abs(a[2] - b[2]);

    return (dist_sq == r_sum * r_sum) || (dist_sq == r_diff * r_diff);
}
void solve()
{
    vector<array<ll, 3>> v;
    ll x, y, r;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> r;
        v.push_back({x, y, r});
    }
    vector<vector<ll>> ve(n + 10);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isTangent(v[i], v[j]))
            {

                ve[i].push_back(j);
                ve[j].push_back(i);
            }
        }
    }
    vector<ll> vis(n + 10, -1);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] != -1)
        {
            continue;
        }
        vis[i] = 0;
        queue<ll> q;
        q.push(i);
        bool flag = 1;
        ll cnt = 0;
        while (q.size())
        {
            ll u = q.front();
            q.pop();
            cnt += vis[u] ? 1 : -1;
            for (auto it : ve[u])
            {
                if (vis[it] == -1)
                {
                    vis[it] = vis[u] ^ 1;
                    q.push(it);
                }
                else
                {
                    if (vis[it] == vis[u])
                    {
                        flag = 0;
                        // cout << "NO\n";
                        // return;
                    }
                }
            }
        }
        if (cnt && flag)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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