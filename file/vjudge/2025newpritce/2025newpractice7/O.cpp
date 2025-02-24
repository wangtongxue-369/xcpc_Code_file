#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod1 = 1e9 + 7;
const ll mod2 = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    map<PII, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        string s;
        ll c1 = 0, c2 = 0;
        ll b1 = base1, b2 = base2;
        cin >> s;
        for (auto c : s)
        {
            c1 = (c1 + b1 * c) % mod1;
            c2 = (c2 + b2 * c) % mod2;
            ans += ma[{c1, c2}];
            ma[{c1, c2}]++;
            b1 = (b1 * base1) % mod1;
            b2 = (b2 * base2) % mod2;
        }
    }
    cout << ans << '\n';
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
