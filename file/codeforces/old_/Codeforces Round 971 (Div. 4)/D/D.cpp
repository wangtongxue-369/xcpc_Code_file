#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lld 0x3f
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0; // a[500005], f[500005];
void solve()
{
    ans = 0;
    cin >> n;
    vector<ll> ve0, ve1;
    ll x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        if (y == 0)
        {
            ve0.push_back(x);
        }
        else
        {
            ve1.push_back(x);
        }
    }
    sort(ve0.begin(), ve0.end());
    sort(ve1.begin(), ve1.end());
    ll n0 = ve0.size(), i0 = 0;
    ll n1 = ve1.size(), i1 = 0;
    while (i0 < n0 && i1 < n1)
    {
        if (ve0[i0] == ve1[i1])
        {
            ans += (n - 2);
            i0++;
            i1++;
            continue;
        }
        if (ve0[i0] < ve1[i1])
        {
            i0++;
        }
        else
        {
            i1++;
        }
    }
    for (int i = 0; i < n0; i++)
    {
        }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
