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
ll _ = 1, n, m, ans[MAXN], a[MAXN], s[MAXN]; // sw[MAXN], js[MAXN];
void solve()
{
    ll k;
    cin >> n >> k >> m;
    for (int i = 0; i <= k; i++)
    {
        s[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = 0;
        cin >> a[i];
    }
    if (m <= n * 2)
    {
        for (int i = 0; i < m; i++)
        {
            if (s[a[i % n]] >= 1)
            {
                s[a[i % n]]--;
                ans[i % n]++;
            }
            else
            {
                s[a[i % n]]++;
            }
        }
    }
    else
    {
        for (int i = 0; i < 2 * n; i++)
        {
            if (s[a[i % n]] >= 1)
            {
                s[a[i % n]]--;
                ans[i % n]++;
            }
            else
            {
                s[a[i % n]]++;
            }
        }
        ll cs;
        if ((m / n) % 2 == 1)
        {
            cs = (m / n) - 1;
        }
        else
        {
            cs = m / n;
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] *= (cs / 2);
        }
        for (ll i = cs * n; i < m; i++)
        {
            if (s[a[i % n]] >= 1)
            {
                s[a[i % n]]--;
                ans[i % n]++;
            }
            else
            {
                s[a[i % n]]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
    }
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
