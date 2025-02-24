#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; //
void solve()
{
    cin >> n >> m;
    ll v;
    vector<ll> f{0};
    vector<ll> dp{0};
    ll s = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v;
        if (v > 0)
        {
            if (v < f.size())
            {
                f[v]++;
            }
        }
        else if (v < 0)
        {
            v = -v;
            v = s - v;
            if (v >= 0)
            {
                f[0]++;
                f[v + 1]--;
            }
        }
        else
        {
            for (int j = 1; j <= s; j++)
            {
                f[j] += f[j - 1];
            }
            for (int j = 0; j <= s; j++)
            {
                dp[j] += f[j];
            }
            dp.push_back(0);
            s++;
            for (int j = s; j >= 1; j--)
            {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            f.assign(s + 1, 0);
        }
    }
    for (int j = 1; j <= s; j++)
    {
        f[j] += f[j - 1];
    }
    for (int j = 0; j <= s; j++)
    {
        dp[j] += f[j];
    }
    cout << *max_element(dp.begin(), dp.end());
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
