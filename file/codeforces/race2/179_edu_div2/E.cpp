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
    ll q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll x, y;
    ll scb = 0, sca = 0, sba = 0;
    while (q--)
    {
        cin >> x >> y;
        if (x == 'c' && y == 'b')
        {
            scb++;
        }
        if (x == 'c' && x == 'a')
        {
            sca++;
        }
        if (x == 'b' && x == 'a')
        {
            sba++;
        }
    }
    for (auto it:s)
    [
        if (it=='c')
        {
            if (sca)
        }
    ]
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