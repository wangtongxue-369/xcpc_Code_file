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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
void solve()
{
    cin >> n >> m;
    queue<ll> q1, q2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        q1.push(a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        q2.push(b[i]);
    }
    ll t = 0;
    ans = 0;
    while (1)
    {
        if (q1.empty() || q2.empty())
        {
            break;
        }
        ll p1 = q1.front();
        ll p2 = q2.front();
        q1.pop(), q2.pop();
        while (1)
        {
            if (p1 == p2)
            {
                break;
            }
            if (p1 < p2)
            {
                t = q1.front();
                q1.pop();
                p1 += t;
                ans++;
                continue;
            }
            if (p1 > p2)
            {
                t = q2.front();
                q2.pop();
                p2 += t;
                ans++;
                continue;
            }
        }
    }
    while (!q1.empty())
    {
        q1.pop();
        ans++;
    }
    while (!q2.empty())
    {
        q2.pop();
        ans++;
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