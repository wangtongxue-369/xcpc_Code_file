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
    for (int i = 2; i <= n / 2; i++)
    {
        if (a[i] == a[i - 1])
        {
            swap(a[i], a[n - i + 1]);
            continue;
        }
        if (a[n - i + 1] == a[n - i + 2])
        {
            swap(a[i], a[n - i + 1]);
            continue;
        }
    }
    ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
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
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
