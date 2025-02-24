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
vector<set<ll>> ve(MAXN + 10);
vector<ll> du(MAXN + 10, 0);
void solve()
{
    ll q;
    cin >> n >> q;
    ll cnt = n;
    ll op, u, v;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> u >> v;
            if (du[u] == 0)
            {
                cnt--;
            }
            if (du[v] == 0)
            {
                cnt--;
            }
            du[u]++;
            du[v]++;
            ve[u].insert(v);
            ve[v].insert(u);
            cout << cnt << '\n';
            continue;
        }
        else
        {
            cin >> v;
            if (ve[v].size() == 0)
            {
                cout << cnt << '\n';
                continue;
            }
            for (auto &it : ve[v])
            {
                ve[it].erase(v);
                du[it]--;
                if (du[it] == 0)
                {
                    cnt++;
                }
            }
            ve[v].clear();
            du[v] = 0;
            cnt++;
            cout << cnt << '\n';
        }
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
