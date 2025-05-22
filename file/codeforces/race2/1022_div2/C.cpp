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
    map<ll, ll> ma;
    ll p = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[p];
        if (a[p] != a[p - 1])
        {
            p++;
        }
    }
    p--;
    ans = 0;
    // cout << p << '\n';
    if (p == 1)
    {
        cout << 1 << '\n';
        return;
    }
    if (a[1] > a[2])
    {
        ans++;
    }
    if (a[p - 1] < a[p])
    {
        ans++;
    }
    for (int i = 2; i < p; i++)
    {
        if (a[i - 1] < a[i] && a[i] > a[i + 1])
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