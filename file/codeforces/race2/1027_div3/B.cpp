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
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll s0 = 0, s1 = 0;
    ll p = n / 2 - k;
    for (auto it : s)
    {
        if (it == '0')
        {
            s0++;
        }
        else
        {
            s1++;
        }
    }
    if (!(s0 - p >= 0 && s1 - p >= 0))
    {
        cout << "NO\n";
        return;
    }
    s0 -= p;
    s1 -= p;
    if (s0 / 2 + s1 / 2 >= k)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
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