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
    vector<ll> a(n + 100, 0);
    if (n % 2 == 1)
    {
        if (n <= 25)
        {
            cout << -1 << '\n';
            return;
        }
        ll x = 1;
        a[1] = x;
        a[10] = x;
        a[26] = x;
        x++;
        a[27] = x;
        a[23] = x;
        x++;
        ll d = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > 0)
            {
                continue;
            }
            else
            {
                a[i] = x;
                x += d;
                d ^= 1;
            }
        }
    }
    else
    {
        ll x = 1;
        for (int i = 1; i <= n; i++)
        {
            a[i] = x;
            if (i % 2 == 0)
            {
                x++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
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
