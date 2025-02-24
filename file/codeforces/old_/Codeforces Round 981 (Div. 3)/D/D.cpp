#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        // a[i]+=a[i-1];
        // ma[a[i]]++;
    }
    ll tmp = 0;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        tmp += a[i];
        if (tmp == 0)
        {
            ans++;
            ma.clear();
            tmp = 0;
            continue;
        }
        if (ma[tmp] > 0)
        {
            ans++;
            ma.clear();
            tmp = 0;
            continue;
        }
        ma[tmp]++;
    }
    cout << ans << '\n';
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
