#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 400005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0;
void solve()
{
    cin >> n;
    vector<int> a(n + 10, 0);
    vector<int> b(n + 10, 0);
    vector<ll> f(n + 10, 1e18);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while (!q.empty())
    {
        auto [x, i] = q.top();
        q.pop();
        if (f[i] < 1e18)
        {
            continue;
        }
        f[i] = min(f[i], x);
        if (b[i] > i)
        {
            q.push({x + (ll)a[i], (ll)b[i]});
        }
        if (i > 0)
        {
            q.push({x, i - 1});
        }
    }
    ans = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        ans = max(ans, sum - f[i]);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
