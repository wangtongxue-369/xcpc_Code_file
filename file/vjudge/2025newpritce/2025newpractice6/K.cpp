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
ll tx[] = {2, 1, -1, -2, -2, -1, 1, 2};
ll ty[] = {1, 2, 2, 1, -1, -2, -2, -1};
void solve()
{
    set<PII> se;
    cin >> n >> m;
    ll x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        se.insert({x, y});
        for (int i = 0; i < 8; i++)
        {
            ll xx = x + tx[i];
            ll yy = y + ty[i];
            if (1 <= xx && xx <= n && 1 <= yy && yy <= n)
            {

                se.insert({xx, yy});
            }
        }
    }
    cout << n * n - se.size() << '\n';
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
