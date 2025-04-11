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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN][2];
ll l[MAXN], r[MAXN];
void solve()
{
    // memset(f, INF, sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    f[1][0] = (r[1] - 1) + (r[1] - l[1]);
    f[1][1] = (r[1] - 1);
    for (int i = 2; i <= n; i++)
    {
        f[i][0] = min(f[i - 1][0] + abs(l[i - 1] - r[i]) + r[i] - l[i] + 1, f[i - 1][1] + abs(r[i - 1] - r[i]) + r[i] - l[i] + 1);
        f[i][1] = min(f[i - 1][0] + abs(l[i - 1] - l[i]) + r[i] - l[i] + 1, f[i - 1][1] + abs(r[i - 1] - l[i]) + r[i] - l[i] + 1);
    }
    cout << (f[n][0] + n - l[n], f[n][1] + n - r[n]) << '\n';
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