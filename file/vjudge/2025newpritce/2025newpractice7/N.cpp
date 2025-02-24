#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 200005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, k[MAXN], c[MAXN];
vector<vector<ll>> a(MAXN + 10);
vector<ll> fa(MAXN + 10, 0);
ll find(ll x)
{
    if (fa[x] == x)
    {
        return x;
    }
    return fa[x] = find(fa[x]);
}
void unio(ll x, ll y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        fa[x] = y;
    }
}
void solve()
{
    cin >> n >> m;
    ll x;
    vector<PII> ve;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> k[i] >> c[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> x;
            a[i].emplace_back(x);
        }
        ve.emplace_back(c[i], i);
    }
    sort(ve.begin(), ve.end());
    for (auto [x, i] : ve)
    {
        ll cnt = 0;
        map<ll, ll> b;
        for (auto it : a[i])
        {
            if (b[find(it)] == 0)
            {
                b[find(it)] = 1;
                cnt++;
            }
        }
        ans += (cnt - 1) * x;
        for (int j = 0; j < a[i].size() - 1; j++)
        {
            unio(a[i][j], a[i][j + 1]);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (find(1) != find(i))
        {
            cout << -1 << '\n';
            return;
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
