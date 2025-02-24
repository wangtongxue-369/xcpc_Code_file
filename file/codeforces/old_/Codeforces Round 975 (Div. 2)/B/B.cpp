#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], k[N];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> k[i];
    }
    map<ll, ll> ma;
    ll li;
    for (int i = 1; i < n; i++)
    {
        li = (i - 1) * (n - i + 1) + (n - i);
        ma[li]++;
        li = (i) * (n - i);
        ma[li] += (a[i + 1] - a[i] - 1);
    }
    ma[(n - 1)]++;
    for (int i = 1; i <= m; i++)
    {
        cout << ma[k[i]] << ' ';
    }
    cout << '\n';
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
