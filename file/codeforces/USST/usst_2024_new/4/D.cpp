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
    string x, y;
    cin >> x >> y;
    string s;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == y[i])
        {
            s += x[i];
        }
        else if (x[i] > y[i])
        {
            s += y[i];
        }
        else if (x[i] < y[i])
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << s << '\n';
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
