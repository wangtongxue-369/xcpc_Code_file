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
void solve()
{
    ll x;
    cin >> n >> x;
    ll tag = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == x)
        {
            tag = i;
        }
    }
    ll l = 1, r = n + 1;
    vector<PII> ve;
    ans = 0;
    while ((r - l > 1))
    {
        m = (r + l) / 2;
        if (a[m] <= x)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << 1 << '\n';
    cout << tag << ' ' << l << '\n';
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
