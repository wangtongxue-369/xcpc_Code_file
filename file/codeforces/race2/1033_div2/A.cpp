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
    ll l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if (l1 == l2 && l2 == l3)
    {
        if (b1 + b2 + b3 == l1)
        {
            cout << "YES\n";
            return;
        }
    }
    if (b1 == b2 && b2 == b3)
    {
        if (l1 + l2 + l3 == b1)
        {
            cout << "YES\n";
            return;
        }
    }
    if (l2 + l3 == l1 && b2 == b3 && b1 + b2 == l1)
    {
        cout << "YES\n";
        return;
    }
    if (b2 + b3 == b1 && l2 == l3 && l1 + l2 == b1)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
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