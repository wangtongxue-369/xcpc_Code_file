#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 25005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    memset(f, 0, sizeof(f));
    cin >> n;
    ll maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    ans = 0;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (f[a[i]] == 1)
        {
            continue;
        }
        ans++;
        f[a[i]] = 1;
        for (int j = 0; j <= maxn; j++)
        {
            if (f[j] && j + a[i] <= maxn)
            {
                f[j + a[i]] = 1;
            }
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
