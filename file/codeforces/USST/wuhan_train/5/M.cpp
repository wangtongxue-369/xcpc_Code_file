
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<int, int> mp, mpp;
    for (int i = 1; i <= n; i++)
    {
        mp[a[i]]++;
    }
    sort(a.begin() + 1, a.end(), greater<>());
    auto dfs = [&](auto &&self, int x) -> bool
    {
        if (mp[x])
        {
            mp[x]--;
            mpp[x]++;
            return 1;
        }
        if (x % 2 == 0)
        {
            return 0;
        }
        int y = x / 2, z = x - y;
        if (self(self, y) && self(self, z))
        {
            return 1;
        }
        return 0;
    };
    for (int i = 1; i <= n; i++)
    {
        if (mp[a[i]] == 0)
        {
            continue;
        }
        mp[a[i]]--;
        mpp.clear();
        if (dfs(dfs, a[i] + 1))
        {
            mp[2 * a[i] + 1]++;
            continue;
        }
        for (auto [x, y] : mpp)
        {
            mp[x] += y;
        }
        mpp.clear();
        if (dfs(dfs, a[i] - 1))
        {
            mp[2 * a[i] - 1]++;
            continue;
        }
        for (auto [x, y] : mpp)
        {
            mp[x] += y;
        }
        mp[a[i]]++;
    }
    vector<int> ans;
    for (auto [x, y] : mp)
    {
        while (y--)
            ans.push_back(x);
    }
    sort(ans.begin(), ans.end(), greater<>());
    cout << ans.size() << "\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}