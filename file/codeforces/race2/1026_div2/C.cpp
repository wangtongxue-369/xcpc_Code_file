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
ll _ = 1, n, m, a[MAXN], d[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    ll l, rr;
    vector<PII> f(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i].first >> f[i].second;
    }
    vector<PII> dp(n + 10);
    // 可行区间
    dp[0] = {0, 0};
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {
        auto [l, r] = f[i];
        ll lm, rm;
        if (d[i] == 0)
        {
            lm = dp[i - 1].first;
            rm = dp[i - 1].second;
        }
        if (d[i] == 1)
        {
            lm = dp[i - 1].first + 1;
            rm = dp[i - 1].second + 1;
        }
        if (d[i] == -1)
        {
            lm = dp[i - 1].first;
            rm = dp[i - 1].second + 1;
        }
        lm = max(lm, l);
        rm = min(rm, r);
        if (lm > rm)
        {
            cout << "-1\n";
            return;
        }
        dp[i] = {lm, rm};
    }
    vector<ll> ans(n + 10);
    ll p = dp[n].first;
    for (int i = n; i >= 1; i--)
    {
        if (!(d[i] == -1))
        {
            ans[i] = d[i];
            p -= d[i];
            continue;
        }
        if (p >= dp[i - 1].first && p <= dp[i - 1].second)
        {
            ans[i] = 0;
        }
        else
        {
            ans[i] = 1;
            p -= 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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