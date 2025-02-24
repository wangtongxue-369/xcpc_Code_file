#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 10010;
ll _ = 1, n, m, ans = 0, a[MAXN], a2[MAXN];
void solve()
{
    memset(a, 0, sizeof(a));
    ll l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    ll p = 0;
    ans = 0;
    bool flag = 0;
    if (r2 <= l1 - 1 || r1 <= l2 - 1)
    {
        cout << 1 << '\n';
        return;
    }
    for (int i = 1; i <= 100; i++)
    {
        if (l1 <= i && i <= r1)
        {
            a[i]++;
        }
        if (l2 <= i && i <= r2)
        {
            a[i]++;
        }
    }
    for (int i = 1; i <= 100; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }
        if (a[i - 1] == 1 && a[i] == 2)
        {
            ans += 1;
            continue;
        }
        if (a[i - 1] == 2 && a[i] == 2)
        {
            ans += 1;
            continue;
        }
        if (a[i - 1] == 2 && a[i] == 1)
        {
            ans += 1;
            continue;
        }
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
