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
    if (n % 2 == 1)
    {
        cout << "NO\n";
        return;
    }
    ll x = 'A';
    cout << "YES\n";
    for (int i = 1; i <= n / 2; i++)
    {
        cout << (char)x << (char)x;
        x += 1;
        if (x > 'Z')
        {
            x = 'A';
        }
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
