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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
void solve()
{
    ll k;
    cin >> n >> m >> k;
    map<ll, ll> c, ma;
    set<ll> se;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        se.insert(b[i]);
        c[b[i]]++;
        // ma[b[i]]++;
    }
    ans = 0;
    ll sum = 0;
    for (int i = 1; i <= m; i++)
    {
        if (c.contains(a[i]))
        {
            ma[a[i]]++;
            if (ma[a[i]] <= c[a[i]])
            {
                sum++;
            }
        }
        else
        {
            continue;
        }
    }
    if (sum >= k)
    {
        ans++;
    }
    for (int r = m + 1; r <= n; r++)
    {
        ll l = r - m + 1;
        if (c.contains(a[l - 1]))
        {
            if (ma[a[l - 1]] > c[a[l - 1]])
            {
            }
            else
            {
                sum--;
            }
            ma[a[l - 1]]--;
        }
        if (c.contains(a[r]))
        {
            ma[a[r]]++;
            if (ma[a[r]] <= c[a[r]])
            {
                sum++;
            }
        }
        if (sum >= k)
        {
            ans++;
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
