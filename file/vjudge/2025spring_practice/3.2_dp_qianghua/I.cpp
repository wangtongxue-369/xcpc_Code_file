#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN][MAXN];
void solve()
{
    ans = 0;
    ll x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        bool flag = 0;
        ll p = 0;
        for (ll j = i; j <= n; j++)
        {
            if (!(a[j - 1] <= a[j]))
            {
                flag = 1;
                p = j;
                break;
            }
        }
        if (flag)
        {
            if (x < a[i])
            {
                swap(a[i], x);
                ans++;
                continue;
            }
            if (a[i] < a[i - 1])
            {
                cout << -1 << '\n';
                return;
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