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
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = 1;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (abs(a[i] - a[j]) % k == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout << "YES\n";
            cout << i << '\n';
            return;
        }
    }
    cout << "NO\n";
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
