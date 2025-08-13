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
    ll gc = a[1];
    for (int i = 1; i <= n; i++)
    {
        gc = __gcd(gc, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] /= gc;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1] + 1)
        {
            cout << "NO\n";
            return;
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