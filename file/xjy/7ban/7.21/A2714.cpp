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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        bool f = 0;
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
            {
                continue;
            }
            for (int k = j + 1; k <= n; k++)
            {
                if (a[k] == a[j] || k == i)
                {
                    continue;
                }
                if (a[k] + a[j] == a[i])
                {
                    ans++;
                    f = 1;
                    break;
                }
            }
            if (f)
                break;
        }
    }
    cout << ans << '\n';
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