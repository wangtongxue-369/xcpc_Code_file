#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 998244353;
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
    for (int k = 1; k <= min((ll)40, n); k++)
    {
        ll maxn = 0, minn = 1e9;
        for (int i = 1; i <= n; i++)
        {
            maxn = max(maxn, a[i]);
            minn = min(minn, a[i]);
        }
        ll mid = (maxn + minn) / 2;
        for (int i = 1; i <= n; i++)
        {
            a[i] = abs(a[i] - mid);
        }
    }
    if (n <= 40)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (a[i] != a[j])
                {
                    ans += abs(a[i] - a[j]);
                    ans %= mod;
                }
            }
        }
        cout << ans << '\n';
        return;
    }
    else
    {
        ll q0 = 0, q1 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                ans += q1;
                q0++;
            }
            else
            {
                ans += q0;
                q1++;
            }
            ans %= mod;
        }
        cout << ans << '\n';
    }
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