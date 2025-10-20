/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
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
ll _ = 1, n, m, ans = 0; // a[MAXN], b[MAXN];
ll x[MAXN];
bool cmp(PII s1, PII s2)
{
    if (s1.second == s2.second)
    {
        return s1.first < s2.first;
    }
    return s1.second < s2.second;
}
void init()
{
    x[0] = 1, x[1] = 1;
    for (int i = 2; i <= 2e5 + 5; i++)
    {
        if (x[i])
            continue;
        for (int j = i; j <= 2e5 + 5; j += i)
            x[j] = i;
    }
}
void solve()
{
    ans = 1e18;
    cin >> n;
    vector<PII> a(n + 10);
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].second;
    }
    for (int i = 1; i <= n; i++)
    {
        ll p = 0;
        ll tmp = a[i].first;
        ll pr = -1;
        while (tmp > 1)
        {
            if (p != x[tmp])
            {
                ma[x[tmp]]++;
            }
            p = x[tmp];
            tmp /= x[tmp];
        }
    }
    for (auto it : ma)
    {
        if (it.second >= 2)
        {
            cout << 0 << '\n';
            return;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        vector<ll> ve;
        ll p = 0;
        ll tmp = a[i].first + 1;
        while (tmp > 1)
        {
            if (p != x[tmp])
            {
                ve.push_back(x[tmp]);
            }
            p = x[tmp];
            tmp /= x[tmp];
        }
        for (auto it : ve)
        {
            if (ma.count(it))
            {
                ans = min(ans, a[i].second);
                break;
            }
        }
    }
    sort(a.begin() + 1, a.begin() + 1 + n, cmp);
    PII mi = a[1];
    ans = min(ans, a[1].second + a[2].second);
    for (auto it : ma)
    {
        ll p = mi.first % it.first;
        if (p == 0)
        {
            continue;
        }
        ans = min(ans, mi.second * (it.first - p));
    }
    cout << ans << '\n';
    // cout << 2 << '\n';
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    init();
    while (_--)
    {
        solve();
    }
    return 0;
}