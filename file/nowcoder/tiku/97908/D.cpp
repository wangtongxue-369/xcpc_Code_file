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
    cin >> n;
    ll maxn = 0, minn = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0)
        {
            f[i] = 1;
            vector<ll> ve;
            ve.push_back(i);
            ll p = a[i];
            while (p != i)
            {
                f[p] = 1;
                ve.push_back(p);
                p = a[p];
                // cout<<p<<'\n';
            }
            // for (auto it : ve)
            // {
            //     cout << it << ' ';
            // }
            // cout << '\n';
            maxn = max(maxn, (ll)ve.size());
            minn = min(minn, (ll)ve.size());
        }
    }
    cout << minn << ' ' << maxn << '\n';
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
