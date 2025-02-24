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
    string s;
    cin >> s;
    ll p = 0;
    ans = 0;
    for (auto it : s)
    {
        if (it == '0')
        {
            p += 10;
            ans += p;
        }
        if (it == '1')
        {
            p -= 5;
            p = max(p, 0ll);
            ans += p;
        }
        if (it == '2')
        {
            p -= 10;
            // p = max(p, 0ll);
            ans += max(p, 0ll);
            p += 10;
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
