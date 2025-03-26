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
bool cmp(PII s1, PII s2)
{
    if (s1.second == s2.second)
    {
        return s1.first > s2.first;
    }
    return s1.second > s2.second;
}
void solve()
{
    map<ll, ll> ma;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            cin >> a[j];
            ma[a[j]]++;
        }
    }
    vector<PII> ve;
    for (auto it : ma)
    {
        ve.push_back(it);
    }
    sort(ve.begin(), ve.end(), cmp);
    cout << ve[0].first << ' ' << ve[0].second << '\n';
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
