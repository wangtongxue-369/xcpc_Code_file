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
ll _ = 1, n, m, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    vector<ll> vis(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<PII> ans;
    for (int i = n - 1; i >= 1; i--)
    {
        vector<ll> v(n + 10, -1);
        for (int j = 1; j <= n; j++)
        {
            if (vis[j])
            {
                continue;
            }
            if (v[a[j] % i] != -1)
            {
                vis[j] = 1;
                // vis[v[a[j] % i]] = 1;
                ans.push_back({v[a[j] % i], j});
                break;
            }
            v[a[j] % i] = j;
        }
    }
    cout << "YES\n";
    reverse(ans.begin(), ans.end());
    for (auto [x, y] : ans)
    {
        cout << x << ' ' << y << '\n';
    }
}
// s1*x+d
// s2*x+d
// 对x取模相等
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
