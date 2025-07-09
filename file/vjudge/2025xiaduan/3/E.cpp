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
ll _ = 1, n, m; // ans = 0;// a[MAXN], f[MAXN];
void solve()
{
    double b, ans = 0;
    char a;
    map<ll, ll> ma;
    ma['D'] = 16;
    ma['C'] = 24;
    ma['B'] = 54;
    ma['A'] = 80;
    ma['S'] = 10000;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        ans += b * ma[a];
    }
    ans = ans * m - 23 * m;
    cout << fixed << setprecision(6) << ans;
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