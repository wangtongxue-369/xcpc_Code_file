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
ll _ = 1, n, m, ans = 0, a[MAXN], l[MAXN], r[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    deque<ll> q;
    q.push_back(0);
    a[0] = 1e18;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && a[i] > a[q.back()])
        {
            q.pop_back();
        }
        l[i] = q.back();
        q.push_back(i);
    }
    q.clear();
    a[n + 1] = 1e18;
    q.push_back(n + 1);
    for (int i = n; i >= 1; i--)
    {

        while (!q.empty() && a[i] > a[q.back()])
        {
            q.pop_back();
        }
        r[i] = q.back();
        q.push_back(i);
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << i << ' ' << l[i] << ' ' << r[i] << '\n';

        ans += i - l[i] - 1;
        if (a[r[i]] != a[i])
        {
            ans += r[i] - i - 1;
        }
    }
    cout << ans << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << l[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << r[i] << ' ';
    // }
    // cout << '\n';
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
