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
    if (n == 1 || n == 3)
    {
        cout << "-1" << '\n';
        return;
    }

    if (n % 2)
    {
        for (int i = 1; i <= n - 4; i++)
        {
            cout << 3;
        }
        cout << 6366 << '\n';
        return;
    }
    else
    {
        for (int i = 1; i <= n - 2; i++)
        {
            cout << 3;
        }
        cout << 66 << '\n';
        return;
    }
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
