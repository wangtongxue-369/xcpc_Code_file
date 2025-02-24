#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, a[MAXN], k;
ll fa[MAXN];
vector<ll> ans(MAXN + 10);
ll qpow(ll pa, ll pb, ll mod)
{
    ll res = 1;
    while (pb)
    {
        if (pb & 1)
        {
            res = res * pa % mod;
        }
        pa = pa * pa % mod;
        pb >>= 1;
    }
    return res;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] != 0)
        {
            continue;
        }
        vector<ll> ve;
        ll p = i;
        do
        {
            ve.push_back(p);
            p = a[p];
        } while (p != i);
        ll s = qpow(2, k, ve.size());
        for (int j = 0; j < ve.size(); j++)
        {
            ans[ve[j]] = ve[(j + s) % ve.size()];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
