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
ll _ = 1, n, m, ans = 0, f[65][40000];
struct node
{
    ll v, p, q;
} a[MAXN];
bool cmp(node s1, node s2)
{
    return s1.q < s2.q;
}
void solve()
{
    cin >> n >> m;
    vector<vector<PII>> ve;
    map<ll, ll> ma;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].v >> a[i].p >> a[i].q;
        if (a[i].q == 0)
        {
            ve.push_back({{a[i].v, a[i].v * a[i].p}});
            ma[i] = ve.size() - 1;
        }
    }
    // sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        if (a[i].q == 0)
        {
        }
        else
        {
            ve[ma[a[i].q]].push_back({a[i].v, a[i].v * a[i].p});
        }
    }
    m = ve.size();
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            ll hf = ve[i - 1][0].first;
            ll ear = ve[i - 1][0].second;
            if (ve[i - 1].size() >= 1 && j - hf >= 0)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - hf] + ear);
            }
            if (ve[i - 1].size() >= 2)
            {
                hf = ve[i - 1][0].first + ve[i - 1][1].first;
                ear = ve[i - 1][0].second + ve[i - 1][1].second;
                if (j - hf >= 0)
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - hf] + ear);
                }
            }
            if (ve[i - 1].size() >= 3)
            {
                hf = ve[i - 1][0].first + ve[i - 1][2].first;
                ear = ve[i - 1][0].second + ve[i - 1][2].second;
                if (j - hf >= 0)
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - hf] + ear);
                }
                hf = ve[i - 1][0].first + ve[i - 1][1].first + ve[i - 1][2].first;
                ear = ve[i - 1][0].second + ve[i - 1][1].second + ve[i - 1][2].second;
                if (j - hf >= 0)
                {
                    f[i][j] = max(f[i][j], f[i - 1][j - hf] + ear);
                }
            }
            ans = max(ans, f[i][j]);
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
