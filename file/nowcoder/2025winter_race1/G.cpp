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
    ll sum = 0, p = ((1 + n) * n) / 2;
    ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum == p)
    {
        sort(a + 1, a + 1 + n);
        for (ll i = 1; i <= n; i++)
        {
            ans += abs(a[i] - i);
        }
        cout << ans / 2 << '\n';
    }
    else
    {
        cout << "-1\n";
        return;
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
