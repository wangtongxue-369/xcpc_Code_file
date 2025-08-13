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
ll _ = 1, n, m, ans = 0, x;
void solve()
{
    ll a, b;
    cin >> a >> b;
    x = abs(a * a - b * b);
    if (x == 3)
    {
        cout << 1 << '\n';
        return;
    }
    if (x == 5)
    {
        cout << 2 << '\n';
        return;
    }
    x -= 5;
    cout << 2 + x - (x + 3) / 4 << '\n';
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