#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 200005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m; // a[4][MAXN]; // f[MAXN];
// ll pa[4][MAXN];

void solve()
{

    cin >> n;
    vector<vector<ll>> a(3, vector<ll>(n, 0));
    vector<vector<ll>> pa(3, vector<ll>(n, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            a[i][j]--;
            pa[i][a[i][j]] = j;
        }
    }
    ll mx[3]{a[0][0], a[1][0], a[2][0]};
    vector<array<ll, 2>> g(n, {-1, -1});
    g[0] = {0, 0};
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (mx[i] > a[i][j])
            {
                g[j] = {i, pa[i][mx[i]]};
            }
        }
        if (g[j][0] != -1)
        {
            for (int i = 0; i < 3; i++)
            {
                mx[i] = max(mx[i], a[i][j]);
            }
        }
    }
    if (g[n - 1][0] == -1)
    {
        cout << "NO\n";
        return;
    }
    stack<pair<ll, ll>> ans;
    for (int i = n - 1; i;)
    {
        auto it = g[i];
        ans.push({it[0], i});
        i = it[1];
    }
    cout << "YES" << '\n';
    cout << ans.size() << '\n';
    while (ans.size() != 0)
    {
        auto it = ans.top();
        ans.pop();
        cout << "qkj"[it.first] << ' ' << it.second + 1 << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
