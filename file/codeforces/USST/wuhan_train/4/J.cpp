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
bool cmp(ll s1, ll s2)
{
    return s1 > s2;
}
void solve()
{
    ll w;
    cin >> n >> w;
    ll x;
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        ma[x]++;
    }
    vector<ll> ve;
    for (auto it : ma)
    {
        ve.push_back(it.second);
    }
    sort(ve.begin(), ve.end(), cmp);
    vector<bool> vis(ve.size() + 10, 0);
    ll p = ve.size();
    ans = 0;
    ll sum = 0;
    for (int i = 0; i < p; i++)
    {
        if (vis[i])
        {
            continue;
        }
        ll ew = w;
        ans++;
        vis[i] = 1;
        ew -= ve[i];
        for (int j = i + 1; j < p; j++)
        {
            if (vis[j])
            {
                continue;
            }
            if (ew >= ve[j])
            {
                ew -= ve[j];
                vis[j] = 1;
            }
        }
    }
    cout << ans << '\n';
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