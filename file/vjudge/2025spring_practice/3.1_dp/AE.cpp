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
    cin >> n;
    vector<ll> l(n + 10, 1);
    vector<ll> r(n + 10, 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ans = 1;
    l[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] < a[i])
        {
            l[i] = l[i - 1] + 1;
        }
        ans = max(ans, l[i]);
    }
    l[n + 1] = 0;
    r[0] = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] < a[i + 1])
        {
            r[i] = r[i + 1] + 1;
        }
        ans = max(ans, r[i]);
    }
    r[n + 1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] < a[i + 1])
        {
            ans = max(ans, l[i - 1] + r[i + 1]);
        }
    }
    cout << ans << '\n';
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
