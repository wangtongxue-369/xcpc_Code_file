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
    return s1.second < s2.second;
}
void solve()
{
    cin >> n;
    ll x, y;
    vector<PII> ji, ou;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        if ((x + y) % 2 == 1)
        {
            ji.emplace_back((x + y + 1) / 2, (x - y + 1) / 2);
        }
        else
        {
            ou.emplace_back((x + y) / 2, (x - y) / 2);
        }
    }
    sort(ou.begin(), ou.end());
    ans = 0;
    ll sum = 0;
    for (ll i = 0; i < ou.size(); i++)
    {
        ans += i * ou[i].first - sum;
        sum += ou[i].first;
    }
    sum = 0;
    sort(ou.begin(), ou.end(), cmp);
    for (ll i = 0; i < ou.size(); i++)
    {
        ans += i * ou[i].second - sum;
        sum += ou[i].second;
    }

    sort(ji.begin(), ji.end());
    sum = 0;
    for (ll i = 0; i < ji.size(); i++)
    {
        ans += i * ji[i].first - sum;
        sum += ji[i].first;
    }
    sum = 0;
    sort(ji.begin(), ji.end(), cmp);
    for (ll i = 0; i < ji.size(); i++)
    {
        ans += i * ji[i].second - sum;
        sum += ji[i].second;
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
