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
char a, b, c;
void hn(ll n, char a, char b, char c)
{
    if (n > 1)
    {
        hn(n - 1, a, c, b);
    }
    cout << a << "->" << n << "->" << b << '\n';
    if (n > 1)
    {
        hn(n - 1, c, b, a);
    }
}
void solve()
{
    ll n;
    cin >> n >> a >> b >> c;
    hn(n, a, b, c);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}