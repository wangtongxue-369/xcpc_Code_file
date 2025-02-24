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
    f[1] = 1;
    f[2] = 2;
    f[3] = 3, f[5] = 5, f[6] = 6;
    n = 7;
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // ma[a[i]]++;
    }
    bool flag = 1;
    for (int i = 1; i <= 7; i++)
    {
        if (f[a[i]] == 0)
        {
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
