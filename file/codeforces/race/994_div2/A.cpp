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
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        ll len = 0;
        if (a[i] == 0)
        {
            continue;
        }
        while (i <= n && a[i] > 0)
        {
            i++;
            len++;
        }
        i--;
        sum++;
    }
    if (sum == 0)
    {
        cout << 0 << '\n';
        return;
    }
    else if (sum == 1)
    {
        cout << 1 << '\n';
        return;
    }
    else if (sum >= 2)
    {
        cout << 2 << '\n';
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
