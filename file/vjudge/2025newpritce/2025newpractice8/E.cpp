#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 550;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
char a[MAXN][MAXN];
string s = "snuke";
vector<PII> dfs(ll x, ll y)
{
    for (int p1 = -1; p1 <= 1; p1 += 2)
    {
        for (int p2 = -1; p2 <= 1; p2 += 2)
        {
            vector<PII> ve;
            for (int i = 0; i < 5; i++)
            {
                ll tx = x + p1 * i, ty = y + p2 * i;
                if (1 <= tx && tx <= n && 1 <= ty && ty <= m && a[tx][ty] == s[i])
                {
                    ve.emplace_back(tx, ty);
                }
                else
                {
                    break;
                }
            }
            if (ve.size() == 5)
            {
                return ve;
            }
        }
    }
    for (int p = -1; p <= 1; p += 2)
    {
        vector<PII> ve;
        for (int i = 0; i < 5; i++)
        {
            ll tx = x + p * i, ty = y;
            if (1 <= tx && tx <= n && 1 <= ty && ty <= m && a[tx][ty] == s[i])
            {
                ve.emplace_back(tx, ty);
            }
            else
            {
                break;
            }
        }
        if (ve.size() == 5)
        {
            return ve;
        }
    }
    for (int p = -1; p <= 1; p += 2)
    {
        vector<PII> ve;
        for (int i = 0; i < 5; i++)
        {
            ll tx = x, ty = y + p * i;
            if (1 <= tx && tx <= n && 1 <= ty && ty <= m && a[tx][ty] == s[i])
            {
                ve.emplace_back(tx, ty);
            }
            else
            {
                break;
            }
        }
        if (ve.size() == 5)
        {
            return ve;
        }
    }
    vector<PII> ve;
    return ve;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    // auto it = dfs(5, 2);
    // for (auto i : it)
    // {
    //     cout << i.first << ' ' << i.second << '\n';
    // }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 's')
            {
                auto it = dfs(i, j);
                if (it.size() == 5)
                {
                    for (auto k : it)
                    {
                        cout << k.first << ' ' << k.second << '\n';
                    }
                    return;
                }
            }
        }
    }
    cout << 0 << ' ' << 0 << '\n';
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
