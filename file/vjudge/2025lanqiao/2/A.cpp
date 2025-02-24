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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll s25 = 0, s50 = 0, s100 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 25)
        {
            s25++;
            continue;
        }
        if (a[i] == 50)
        {
            if (s25 > 0)
            {
                s25--;
                s50++;
            }
            else
            {
                cout << "NO\n";
                return;
            }
            continue;
        }
        if (a[i] == 100)
        {
            if (s50 > 0 && s25 > 0)
            {
                s50--;
                s25--;
                s100++;
                continue;
            }
            if (s25 >= 3)
            {
                s25 -= 3;
                s100++;
                continue;
            }
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
