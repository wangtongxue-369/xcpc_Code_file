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
    cin >> k;
    string s;
    ll p = 1;
    while (cin >> s)
    {
        if (s == "End")
        {
            return;
        }
        if (p % (k + 1) == 0)
        {
            cout << s << '\n';
            p++;
            continue;
        }
        if (s == "ChuiZi")
        {
            cout << "Bu\n";
            p++;
            continue;
        }
        if (s == "JianDao")
        {
            cout << "ChuiZi\n";
            p++;
            continue;
        }
        if (s == "Bu")
        {
            cout << "JianDao\n";
            p++;
            continue;
        }
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
