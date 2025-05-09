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
    map<ll, char> ma;
    for (int i = 0; i <= 9; i++)
    {
        ma[i] = i + '0';
    }
    ma[10] = 'A';
    ma[11] = 'B';
    ma[12] = 'C';
    ma[13] = 'D';
    ma[14] = 'E';
    ma[15] = 'F';
    ma[16] = 'G';
    ll x, p;
    cin >> x >> m;
    p = m;
    while (p <= x)
    {
        p *= m;
    }
    p /= m;
    if (x == 0)
    {
        cout << 0 << '\n';
        return;
    }
    // cout << p << '\n';
    while (p != 0)
    {
        //  cout << x << ' ' << p << '\n';
        ll d = x / p;
        x = x % p;
        cout << ma[d];
        p /= m;
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
