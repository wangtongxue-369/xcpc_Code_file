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
struct node
{
    ll a, b;
} a[MAXN];
void solve()
{
    cin >> n;
    vector<vector<ll>> a(n + 10, vector<ll>(2, 0)), vis(n + 10, vector<ll>(2, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][1];
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][0] < a[i][1])
        {
            ans += a[i][1];
            vis[i][1] = 1;
        }
        else
        {
            ans += a[i][0];
            vis[i][0] = 1;
        }
    }
    ll maxn = -1e18;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i][0])
        {
            maxn = max(maxn, a[i][0]);
        }
        else
        {
            maxn = max(maxn, a[i][1]);
        }
    }
    ans += maxn;
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
