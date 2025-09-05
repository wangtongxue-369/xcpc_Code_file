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
ll _ = 1, n, m, ans = 0, w[MAXN], c[MAXN];
bool cmp(PII s1, PII s2)
{
    return s1 > s2;
}
void solve()
{
    cin >> n;
    vector<vector<ll>> ve(5e5 + 10050);
    for (int i = 2; i <= 5e5; i++)
    {
        if (ve[i].size())
        {
            continue;
        }
        for (int j = i; j <= 5e5; j += i)
        {
            ve[j].push_back(i);
        }
    }
    // ve[i]:i是谁的倍数
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    ans = 1;
    // 以i的倍数结尾的队列最大的两个
    vector<array<PII, 2>> f(MAXN + 10);
    vector<ll> dp(n + 10, 1);
    for (int i = 1; i <= n; i++)
    {
        for (auto it : ve[w[i]])
        {
            // 拿到了他是谁的倍数
            for (auto jk : f[it])
            {
                if (jk.second != c[i])
                {
                    dp[i] = max(dp[i], jk.first + 1);
                }
            }
        }
        ans = max(ans, dp[i]);
        for (auto it : ve[w[i]])
        {
            if (dp[i] > f[it][0].first)
            {
                if (c[i] == f[it][0].second)
                {
                    f[it][0].first = dp[i];
                }
                else
                {
                    f[it][1] = f[it][0];
                    f[it][0] = {dp[i], c[i]};
                }
            }
            else
            {
                if (dp[i] > f[it][1].first && c[i] != f[it][0].second)
                {
                    f[it][1] = {dp[i], c[i]};
                }
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