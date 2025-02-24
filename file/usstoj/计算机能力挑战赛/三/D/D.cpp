#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], f[N];
void solve()
{
    vector<ll> ve;
    for (int i = 1; i < 10000; i++)
    {
        if (i % 7 != 0)
        {
            ve.push_back(i);
        }
    }
    while (cin >> n)
    {
        if (n == 0)
        {
            return;
        }
        for (int i = 0; ve[i] < n; i++)
        {
            cout << ve[i] << ' ';
        }
        cout << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
