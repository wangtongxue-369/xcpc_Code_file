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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<array<long long, 3>>> q;
    for (int i = 1; i <= n; i++)
    {
        q.push({a[i] + b[1], i, 1});
    }
    for (int i = 1; i <= n; i++)
    {
        cout << q.top()[0] << ' ';
        auto [s, x, y] = q.top();
        q.pop();
        if (y + 1 <= n)
        {
            q.push({a[x] + b[y + 1], x, y + 1});
        }
    }
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
