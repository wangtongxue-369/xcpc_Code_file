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
void ask(ll i, ll j, ll k)
{
    cout << "? " << i << ' ' << j << ' ' << k << endl;
}
void solve()
{
    cin >> n;
    a[1] = 1, a[2] = 2, a[3] = 3;
    ll x;
    ll p = 0;
    mt19937 mt(time(nullptr));
    while (1)
    {
        ask(a[1], a[2], a[3]);
        cin >> x;
        if (x == 0)
        {
            break;
        }
        a[mt() % 3 + 1] = x;
        p++;
    }
    cout << "! " << a[1] << ' ' << a[2] << ' ' << a[3] << endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
