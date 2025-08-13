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
    ll p = 2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (p--)
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum = 0;
            if (a[i - 1] == 1)
            {
                sum++;
            }
            if (a[i + 1] == 1)
            {
                sum++;
            }
            if (a[i] == 0 && sum == 1)
            {
                b[i] = 1;
            }
            if (a[i] == 1 && (sum == 0 || sum == 2))
            {
                b[i] = 0;
            }
            if (a[i] == 1 && (sum == 1))
            {
                b[i] = 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            a[i] = b[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
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