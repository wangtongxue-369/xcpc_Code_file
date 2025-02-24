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
PII d[MAXN + 10];
ll x[MAXN + 10], v[MAXN + 10];
void solve()
{
    ll l;
    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i].first >> d[i].second;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i] >> v[i];
    }
    priority_queue<ll> ve;
    ll p = 1;
    ll jump = 1;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (x[p] <= d[i].first && p <= m)
        {
            ve.push(v[p]);
            p++;
        }
        if (d[i].first - 1 + jump <= d[i].second)
        {
            while (d[i].first - 1 + jump <= d[i].second && !ve.empty())
            {
                jump += ve.top();
                ans++;
                ve.pop();
            }
        }
        if (d[i].first - 1 + jump > d[i].second)
        {
            continue;
        }
        else
        {
            cout << "-1\n";
            return;
        }
    }
    cout << ans << '\n';
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
