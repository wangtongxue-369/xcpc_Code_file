#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 100005;
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
    sort(a + 1, a + 1 + n);
    ll sumg = a[1];
    for (int i = 2; i <= n; i++)
    {
        sumg = __gcd(sumg, a[i]);
    }
    ll x = a[1];
    ans = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (x == sumg)
        {
            ans += (n - i + 1) * x;
            break;
        }
        else
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (__gcd(x, a[j]) < __gcd(x, a[i]))
                {
                    swap(a[j], a[i]);
                }
            }
            x = __gcd(x, a[i]);
            ans += x;
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
