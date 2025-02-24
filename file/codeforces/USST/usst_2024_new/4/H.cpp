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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    vector<ll> a;
    ll x;
    a.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        x += a[a.size() - 1];
        a.push_back(x);
    }
    while (k--)
    {
        cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x) - a.begin();

        cout << it << ' ' << x - a[it - 1] << '\n';
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
