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
ll _ = 1, n, m, ans = 0, a[1010][1010], d1[1010][1010], d2[1010][1010], x1[1010][1010], x2[1010][1010];
void solve()
{
    ll k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        deque<ll> q;
        for (int j = 1; j <= m; j++)
        {
            while (!q.empty() && j - k + 1 > q.front())
                q.pop_front();
            while (!q.empty() && a[i][j] > a[i][q.back()])
                q.pop_back();
            q.push_back(j);
            if (j + 1 >= k)
            {
                d1[i][j - k + 1] = a[i][q.front()];
            }
        }
        q.clear();
        for (int j = 1; j <= m; j++)
        {
            while (!q.empty() && j - k + 1 > q.front())
                q.pop_front();
            while (!q.empty() && a[i][j] < a[i][q.back()])
                q.pop_back();
            q.push_back(j);
            if (j + 1 >= k)
            {
                x1[i][j - k + 1] = a[i][q.front()];
            }
        }
    }
    for (int j = 1; j <= m - k + 1; j++)
    {
        deque<ll> q;
        for (int i = 1; i <= n; i++)
        {
            while (!q.empty() && i - k + 1 > q.front())
                q.pop_front();
            while (!q.empty() && d1[i][j] > d1[q.back()][j])
                q.pop_back();
            q.push_back(i);
            if (i + 1 >= k)
            {
                d2[i - k + 1][j] = d1[q.front()][j];
            }
        }
        q.clear();
        for (int i = 1; i <= n; i++)
        {
            while (!q.empty() && i - k + 1 > q.front())
                q.pop_front();
            while (!q.empty() && x1[i][j] < x1[q.back()][j])
                q.pop_back();
            q.push_back(i);
            if (i + 1 >= k)
            {
                x2[i - k + 1][j] = x1[q.front()][j];
            }
        }
    }
    ans = 1e18;
    for (int i = 1; i <= n - k + 1; i++)
    {
        for (int j = 1; j <= m - k + 1; j++)
        {
            ans = min(ans, d2[i][j] - x2[i][j]);
        }
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
