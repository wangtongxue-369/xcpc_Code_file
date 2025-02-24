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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> ve;
    for (int i = 1; i <= n; i++)
    {
        ve.push_back(a[i]);
        if (ve.size() == 1 || ve.size() == 0)
        {
            continue;
        }
        if (ve[ve.size() - 1] != ve[ve.size() - 2])
        {
            continue;
        }
        while (ve.size() >= 2 && ve[ve.size() - 1] == ve[ve.size() - 2])
        {
            ll s = ve.back();
            ve.pop_back(), ve.pop_back();
            ve.push_back(s + 1);
        }
    }
    // for (auto it : ve)

    // {
    //     cout << it << ' ';
    // }
    cout << ve.size() << '\n';
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
