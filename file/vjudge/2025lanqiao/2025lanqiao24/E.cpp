#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 3050;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN][MAXN], f[MAXN];
void solve()
{
    cin >> n;
    ll x, y, w;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> w;
        a[x + 1][y + 1] += w;
    }
    for (int i = 1; i <= 2100; i++)
    {
        for (int j = 1; j <= 2100; j++)
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, x2++, y1++, y2++;
        cout << a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1] << '\n';
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
