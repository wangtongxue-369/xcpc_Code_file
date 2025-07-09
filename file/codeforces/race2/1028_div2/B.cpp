#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, p[MAXN], q[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
    }
    ll mx1 = p[1], mx2 = q[1];
    ll p1 = 0, p2 = 0;
    ll pos1 = 1, pos2 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] > mx1)
        {
            pos1 = i;
            mx1 = max(mx1, p[i]);
        }
        if (q[i] > mx2)
        {
            pos2 = i;
            mx2 = max(mx2, q[i]);
        }
        // cout << mx1 << ' ' << mx2 << '\n';
        if (mx1 > mx2)
        {
            cout << (f[mx1] + f[q[i - pos1 + 1]]) % mod << ' ';
            continue;
        }
        if (mx1 < mx2)
        {
            cout << (f[mx2] + f[p[i - pos2 + 1]]) % mod << ' ';
            continue;
        }
        p1 = q[i - pos1 + 1], p2 = p[i - pos2 + 1];
        if (p1 > p2)
        {
            cout << (f[mx1] + f[q[i - pos1 + 1]]) % mod << ' ';
            continue;
        }
        if (p1 < p2)
        {
            cout << (f[mx2] + f[p[i - pos2 + 1]]) % mod << ' ';
            continue;
        }
        cout << (f[mx1] + f[q[i - pos1 + 1]]) % mod << ' ';
        continue;
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    f[0] = 1;
    for (ll i = 1; i <= 200005; i++)
    {
        f[i] = f[i - 1] * 2;
        f[i] %= mod;
    }
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}