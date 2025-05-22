#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN];
struct node
{
    ll x1, x2, s;
    bool operator<(const node &o) const
    {
        return s > o.s;
    }
};
void solve()
{
    ll k;
    cin >> n >> k;
    priority_queue<node> q;
    vector<array<ll, 2>> f(n + 10);
    vector<ll> vis(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i][0] = i - 1;
        f[i][1] = i + 1;
        if (i >= 2)
        {
            q.push({i - 1, i, a[i - 1] + a[i]});
        }
    }
    ans = 0;
    while (k--)
    {
        auto [x1, x2, s] = q.top();
        q.pop();
        if (vis[x1] || vis[x2])
        {
            k++;
            continue;
        }
        ans += s;
        vis[x1] = 1, vis[x2] = 1;
        ll l = f[x1][0], r = f[x2][1];
        f[l][1] = r, f[r][0] = l;
        if (1 <= r && r <= n && 1 <= l && l <= n)
        {
            q.push({l, r, a[l] + a[r]});
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