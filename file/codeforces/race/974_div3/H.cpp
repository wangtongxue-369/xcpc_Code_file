#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll _ = 1, n, m, ans = 0, a[MAXN + 10], f[MAXN + 10];
void solve()
{
    ll q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = f[a[i]];
        a[i] ^= a[i - 1];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (a[r] ^ a[l - 1])
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= MAXN; i++)
    {
        f[i] = rng();
    }
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
