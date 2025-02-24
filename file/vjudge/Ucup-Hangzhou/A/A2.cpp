#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[500005], f[500005];
void solve()
{
    cin >> n;
    ll l = 1, r = n;
    while (l < r)
    {
        ll xl, xr;
        ll mid = (l + r) >> 1;
        ll midl = (mid + l) >> 1;
        ll midr = (mid + r) >> 1;
        cout << "?" << midl << endl;
        cin >> xl;
        cout << "?" << midr << endl;
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
