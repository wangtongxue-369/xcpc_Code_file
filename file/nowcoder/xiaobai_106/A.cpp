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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void ji()
{
    cout << "YES\n";
}
void ou()
{
    cout << "NO\n";
}
void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b == 0)
    {
        if (c % 2 == 0 && d % 2 == 0)
        {
            ou();
        }
        else if (c % 2 == 1 && d % 2 == 1)
        {
            ou();
        }
        else
        {
            ji();
        }
        return;
    }
    if ((a % 2 == 0 || c % 2 == 0))
    {
        if (d % 2 == 0)
        {
            ou();
            return;
        }
        else
        {
            ji();
            return;
        }
    }
    if ((a % 2 == 1 && c % 2 == 1))
    {
        if (d % 2 == 1)
        {
            ou();
        }
        else
        {
            ji();
        }
    }
}
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
