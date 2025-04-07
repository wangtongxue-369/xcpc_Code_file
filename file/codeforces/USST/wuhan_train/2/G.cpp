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
    cin >> n;
    map<ll, vector<ll>> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i] - i].push_back(a[i]);
    }
    ans = 0;
    for (auto [i, ve] : ma)
    {
        sort(ve.begin(), ve.end(), cmp);
        for (int i = 0; i < ve.size(); i++)
        {
            if (i + 1 < ve.size())
            {
                ans += max(0ll, ve[i] + ve[i + 1]);
                i++;
            }
        }
    }
    cout << ans << '\n';
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
