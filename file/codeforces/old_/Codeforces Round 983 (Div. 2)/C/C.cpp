#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    ll maxn = 2;
    for (int i = 1; i <= n - 2; i++)
    {
        ll k = lower_bound(a.begin() + i, a.end(), a[i] + a[i + 1]) - a.begin() - 1;
        if (k > i + 1)
        {
            maxn = max(maxn, k - i + 1);
        }
    }
    cout << n - maxn << '\n';
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
