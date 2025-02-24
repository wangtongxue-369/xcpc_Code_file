#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0, k, a[MAXN], f[MAXN];
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ans = 0;
    ll sum = 0;
    sort(a + 1, a + 1 + n);
    ll d = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x = k - sum;
        if (x <= (a[i] - d) * (n - i + 1))
        {
            sum += x;
            ans += x;
            cout << ans << '\n';
            return;
        }
        else
        {
            sum += (a[i] - d) * (n - i + 1);
            ans += (a[i] - d) * (n - i + 1) + 1;
            d = a[i];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
