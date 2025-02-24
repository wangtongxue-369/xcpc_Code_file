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
    ll k;
    cin >> n >> k;
    vector<ll> ve;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 1)
        {
            continue;
        }
        ll j = i;
        if (j + k <= n && f[j + k] == 0)
        {
            ve.push_back(i);
            f[i] = 1;
        }
        while (j + k <= n && f[j + k] == 0)
        {
            ve.push_back(j + k);
            f[j + k] = 1;
            j += k;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0)
        {
            ve.push_back(i);
        }
    }
    for (auto it : ve)
    {
        cout << it << ' ';
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
