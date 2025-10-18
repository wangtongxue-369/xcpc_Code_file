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
    vector<PII> ve;
    ll l, r;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        ve.push_back({l, r});
        ans += r - l;
    }
    sort(ve.begin(), ve.end(), [&](PII s1, PII s2)
         { return s1.first + s1.second < s2.first + s2.second; });
    ll add = 0;
    for (int i = 0; i < ve.size(); i++)
    {
        if (n % 2 == 1 && i == n / 2)
        {
            continue;
        }
        if ((i + 1) * 2 <= n)
        {
            add -= ve[i].first;
        }
        else
        {
            add += ve[i].second;
        }
    }
    if (n % 2 == 0)
    {
        cout << add + ans << '\n';
        return;
    }
    ans += add;
    ll sum = ans;
    for (int i = 0; i < ve.size(); i++)
    {
        if (i == n / 2)
        {
            continue;
        }
        if ((i + 1) * 2 <= n)
        {
            ans = max(ans, sum + ve[i].first - ve[n / 2].first);
        }
        else
        {
            ans = max(ans, sum + ve[n / 2].second - ve[i].second);
        }
    }
    cout << ans << '\n';
}
// 1 10   9
// 2 15   13
// 3 9    6

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