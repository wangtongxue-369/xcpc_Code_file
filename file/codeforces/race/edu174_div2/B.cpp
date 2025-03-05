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
ll _ = 1, n, m, ans = 0, a[750][750], f[MAXN];
ll tx[] = {0, -1, 0, 1, 0};
ll ty[] = {0, 0, -1, 0, 1};
void solve()
{
    ll x;
    cin >> n >> m;
    vector<vector<PII>> ve(n * m + 10);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            ve[a[i][j]].push_back({i, j});
        }
    }
    ans = 1e18;
    vector<ll> s;
    for (int w = 1; w <= n * m; w++)
    {
        if (ve[w].size() == 0)
        {
            continue;
        }
        bool flag = 0;
        ll v = 1;
        for (auto it : ve[w])
        {
            for (int i = 1; i <= 4; i++)
            {
                ll xx = it.first + tx[i];
                ll yy = it.second + ty[i];
                if (1 <= xx && xx <= n && 1 <= yy && yy <= m && a[xx][yy] == w)
                {
                    v++;
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        s.push_back(v);
    }
    ll sum = 0;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size() - 1; i++)
    {
        // cout << s[i] << ' ';
        sum += s[i];
    }
    cout << sum << '\n';
}
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
