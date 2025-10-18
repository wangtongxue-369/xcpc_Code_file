/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    cin >> m >> n;
    vector<PII> ve;
    ll l, r;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        if (l == r)
        {
            continue;
        }
        ve.push_back({l, r});
    }
    ans = 0;
    sort(ve.begin(), ve.end());
    priority_queue<ll, vector<ll>, greater<ll>> q;
    // 结束位置，包括我的pos的右端点
    ll p = 0;
    ll pos = 1;
    // 维护每个点包括他的区间，按照r排序，优先用前面的
    for (ll i = 0; i < ve.size(); i++)
    {
        l = ve[i].first;
        r = ve[i].second;
        if (l >= pos)
        {
            pos = l + 1;
        }
        while (!q.empty() && q.top() < pos)
        {
            q.pop();
        }
        while (p < ve.size() && ve[p].first < pos)
        {
            q.push(ve[p].second);
            p++;
        }
        if (!q.empty())
        {
            ans++;
            pos++;
            q.pop();
        }
    }
    cout << n - ans << '\n';
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