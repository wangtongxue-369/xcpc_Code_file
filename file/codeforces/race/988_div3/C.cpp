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
bool check(ll x)
{
    bool flag = 1;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
void solve()
{
    cin >> n;
    if (n <= 4)
    {
        cout << -1 << '\n';
        return;
    }
    vector<ll> p;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1 && i != 5)
        {
            cout << i << ' ';
        }
    }
    cout << 5 << ' ' << 4 << ' ';
    for (int i = 1; i <= n; i++)
    {
        if ((i & 1 ^ 1))

        {
            if (i != 4)
            {
                cout << i << ' ';
            }
        }
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << check(9) << '\n';
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
