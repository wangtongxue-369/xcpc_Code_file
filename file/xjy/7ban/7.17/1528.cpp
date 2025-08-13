#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = -1e18;
    a[n + 1] = -1e18;
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] > a[i + 1])
        {
            b[i - 1] += a[i];
        }
        if (a[i - 1] < a[i + 1])
        {
            b[i + 1] += a[i];
        }
        if (a[i - 1] == a[i + 1])
        {
            b[i] += a[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << ' ';
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