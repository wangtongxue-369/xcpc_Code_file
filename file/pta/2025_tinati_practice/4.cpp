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
void solve()
{
    cin >> n;
    map<ll, PII> ma;
    ll s1, s2, s3;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1 >> s2 >> s3;
        ma[s2] = {s1, s3};
    }
    cin >> m;
    while (m--)
    {
        ll w;
        cin >> w;
        cout << ma[w].first << ' ' << ma[w].second << '\n';
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
