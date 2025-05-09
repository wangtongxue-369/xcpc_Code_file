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
void ff(ll x, ll h)
{
    if (x == h)
    {
        bool flag = 1;
        for (int i = 0; i < h; i++)
        {
            ll z = 0, j = 0;
            if (a[(i + 1) % h] == 0)
            {
                j++;
            }
            if (a[(i + 1) % h] == 1)
            {
                z++;
            }
            if (a[(i + 2) % h] == 0)
            {
                j++;
            }
            if (a[(i + 2) % h] == 1)
            {
                z++;
            }
            if (a[i] == 1)
            {
                if (z == 1 && j == 1)
                {
                    continue;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                if (z == 1 && j == 1)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
        {
            for (int i = 0; i < h; i++)
            {
                cout << a[i] << ' ';
                if (a[i] == 0)
                {
                    ans++;
                }
            }
            cout << '\n';
        }
        return;
    }
    a[x] = 1;
    ff(x + 1, h);
    a[x] = 0;
    ff(x + 1, h);
}
void solve()
{
    cin >> n;
    for (int i = 3; i <= n; i++)
    {
        cout << "! " << i << '\n';
        ans = 0;
        ff(0, i);
        cout << i << ' ' << ans << '\n';
    }
    // if (n % 3 == 0)
    // {
    //     cout << n * 2 << '\n';
    // }
    // else
    // {
    //     cout << n << '\n';
    // }
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
