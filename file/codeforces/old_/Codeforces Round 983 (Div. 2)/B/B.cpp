#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN], k;
void solve()
{
    cin >> n >> k;
    if (n == 1)
    {
        cout << 1 << '\n'
             << 1 << '\n';
        return;
    }
    if (k == 1 || k == n)
    {
        cout << -1 << '\n';
        return;
    }
    int x = n - k;
    if (x % 2 != 0 && (k - 1) % 2 != 0)
    {
        cout << 3 << '\n';
        cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
        return;
    }
    if (x % 2 == 0 && (k - 1) % 2 == 0)
    {
        cout << 3 << '\n';
        cout << 1 << ' ' << k - 1 << ' ' << k + 2 << '\n';
        return;
    }
    cout << -1 << '\n';
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
