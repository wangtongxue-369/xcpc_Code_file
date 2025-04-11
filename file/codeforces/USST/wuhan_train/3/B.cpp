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
    ll sum = 0;
    map<ll, vector<ll>> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        ma[a[i]].push_back(i);
    }

    ll p = sum * 2 / n;
    for (int i = 1; i <= n; i++)
    {
        if (ma[p - a[i]].size() > 0)
        {
            f[i] = ma[p - a[i]].back();
            ma[p - a[i]].pop_back();
        }
        else
        {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << f[i] << ' ';
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}