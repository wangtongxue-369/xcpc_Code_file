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
ll _ = 1, n, m, ans = 0;
void solve()
{
    ll a, b;
    ll s1, s2, d1, d2;
    cin >> a >> b;
    cin >> n;
    ll p1 = 0, p2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1 >> s2 >> d1 >> d2;
        bool f1 = 0, f2 = 0;
        if (s2 == s1 + d1)
        {
            f1 = 1;
        }
        if (d2 == s1 + d1)
        {
            f2 = 1;
        }
        if (f1 && f2)
        {
            continue;
        }
        if (f1 && !f2)
        {
            p1++;
            // cout << i << ' ' << p1 << ' ' << p2 << '\n';
            if (p1 > a)
            {
                cout << "A\n";
                cout << p2 << '\n';
                return;
            }
        }
        if (!f1 && f2)
        {
            p2++;
            if (p2 > b)
            {
                cout << "B\n";
                cout << p1 << '\n';
                return;
            }
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
