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
    bool flag = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            sum++;
            flag = 1;
        }
    }
    if (!flag)
    {
        cout << 1 << '\n';
        cout << 1 << ' ' << n << '\n';
    }
    else
    {
        if (a[1] != 0)
        {
            cout << 2 << '\n';
            cout << 2 << ' ' << n << '\n';
            cout << 1 << ' ' << 2 << '\n';
        }
        else
        {
            if (a[n] == 0)
            {
                cout << 3 << '\n';
                cout << 1 << ' ' << 2 << '\n';
                cout << 2 << ' ' << n - 1 << '\n';
                cout << 1 << ' ' << 2 << '\n';
            }
            else
            {
                cout << 2 << '\n';
                cout << 1 << ' ' << n - 1 << '\n';
                cout << 1 << ' ' << 2 << '\n';
            }
        }
    }
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