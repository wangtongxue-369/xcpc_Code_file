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
ll _ = 1, n, m, ans = 0, a[550][550], f[MAXN];
void solve()
{
    cin >> n;
    ll p = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            a[i][j] = p;
            p++;
        }
        int j = i;
        for (int k = i + 1; k <= n; k++)
        {
            a[k][j] = a[i][k - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
// 1 2 3 4
// 1 5 6 7
// 2 5 8 9
// 3 6 9 10
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
