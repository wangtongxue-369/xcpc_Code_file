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
ll find_min_k(ll x, ll y)
{
    ll k = 0, carry = 0;
    for (int i = 0; i < 60; i++)
    {
        int x_bit = ((x + k) >> i);
        int y_bit = ((y + k) >> i);

        if ((x_bit + carry) & (y_bit + carry))
        {

            k |= (1LL << i);
            if (((x_bit + carry) & 1) & ((y_bit + carry) & 1))
            {
                carry = 1;
            }
        }
        else
        {
            carry = 0;
        }
    }
    return k;
}
void solve()
{
    ll x, y;
    cin >> x >> y;
    ll xb, yb;
    if (x == y)
    {
        cout << -1 << '\n';
        return;
    }
    cout << (1ll << 50) - max(x, y) << '\n';
}
// (x+k)&(y+k)=0
//    32  16  8   4   2  1
// 19  0   1  0   0   1  1
// 10  0   0  1   0   1  0

//    32  16  8   4   2  1
// 19  0   1  0   1   0  1
// 10  0   0  1   1   0  0

//    32  16  8   4   2  1
// 19  0   1  1   0   0  1
// 10  0   1  0   0   0  0

// (x+k)+(y+k)=
// (x+k)+(y+k)=(x+k)^(y+k)
// (x+k)+(y+k)=(x+k+y+k)-2*((x+k)&(y+k))
// (x+k)&(y+k)=0
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