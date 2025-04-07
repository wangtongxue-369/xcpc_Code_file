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
ll _ = 1, n, m, ans = 0, f[2][210][26 * 201];
struct node
{
    ll a;
    ll s5 = 0, s2 = 0;
} a[MAXN];
void solve()
{
    memset(f, -1, sizeof(f));
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a;
        ll p = a[i].a;
        while (p % 5 == 0)
        {
            a[i].s5++;
            p /= 5;
        }
        p = a[i].a;
        while (p % 2 == 0)
        {
            a[i].s2++;
            p /= 2;
        }
    }
    f[0][0][0] = 0;
    ll s = 0, t = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k && j <= i; j++)
        {
            for (int w = 0; w <= 26 * 200; w++)
            {
                f[t][j][w] = f[s][j][w];
                if (j - 1 >= 0 && i - 1 >= 0 && w - a[i].s5 >= 0 && f[s][j - 1][w - a[i].s5] >= 0)
                {
                    f[t][j][w] = max(f[t][j][w], f[s][j - 1][w - a[i].s5] + a[i].s2);
                }
            }
        }
        swap(s, t);
    }
    ans = 0;
    for (int w = 0; w <= 26 * 200; w++)
    {
        ans = max(ans, (ll)min((ll)w, f[s][k][w]));
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
