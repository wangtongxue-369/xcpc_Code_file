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
    ll p;
    if (a[1] < 10)
    {
        p = a[1];
    }
    else
    {
        if (a[1] % 10 >= a[1] / 10)
        {
            p = a[1] % 10;
        }
        else
        {
            p = a[1];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] < 10)
        {
            if (p > a[i])
            {
                cout << "NO\n";
                return;
            }
            else
            {
                p = a[i];
            }
        }
        else
        {
            ll p2 = a[i] % 10, p1 = a[i] / 10;
            if (p <= p1 && p1 <= p2)
            {
                p = p2;
                continue;
            }
            else
            {
                if (p <= a[i])
                {
                    p = a[i];
                    continue;
                }
                else
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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
