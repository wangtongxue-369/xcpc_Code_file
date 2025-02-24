#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e8;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    vector<ll> a;
    cin >> n;
    ans = 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
        sum += x;
    }
    sort(a.begin(), a.end());
    ans = (n - 1) * sum;
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        ll c = mod - a[i];
        auto s = lower_bound(a.begin() + i + 1, a.end(), c);
        if (s == a.end())
        {
            continue;
        }
        ll x = s - a.begin();
        cnt += (n - x);
    }
    cout << ans - cnt * mod << '\n';
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
