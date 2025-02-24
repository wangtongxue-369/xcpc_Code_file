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
ll _ = 1, n, m, ans = 0;
void solve()
{
    ll q, w;
    cin >> n >> m >> q;
    vector<ll> a;
    for (int i = 1; i <= q; i++)
    {
        cin >> w;
        a.push_back(w);
    }
    vector<array<ll, 2>> c;
    bool flag = 1;
    c.push_back({m, m});
    for (auto x : a)
    {
        bool addlr = 0;
        for (int i = c.size() - 1; i >= 0; i--)
        {
            if (c[i][0] <= x && x <= c[i][1])
            {
                if (x == c[i][0] && x == c[i][1] && x != 1 && x != n)
                {
                    c.erase(c.begin() + i);
                }
                addlr = 1;
                continue;
            }
            if (x < c[i][0])
            {
                c[i][0]--;
                continue;
            }
            if (x > c[i][1])
            {
                c[i][1]++;
                continue;
            }
        }
        bool s1 = 1, s2 = 1;
        if (addlr && flag)
        {
            flag = 0;
            for (int i = 0; i < c.size(); i++)
            {
                if (c[i][0] <= 1 && 1 <= c[i][0])
                {
                    s1 = 0;
                }
                if (c[i][0] <= n && n <= c[i][0])
                {
                    s2 = 0;
                }
            }
            if (s1)
            {
                c.push_back({1, 1});
            }
            if (s2)
            {
                c.push_back({n, n});
            }
        }
        ans = 0;
        sort(c.begin(), c.end());
        ans += c[0][1] - c[0][0] + 1;
        for (int i = 1; i < c.size(); i++)
        {
            ll l = c[i][0], r = c[i][1];
            if (c[i][0] <= c[i - 1][1])
            {
                l = c[i - 1][1] + 1;
            }
            ans += r - l + 1;
        }
        cout << ans << ' ';
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
