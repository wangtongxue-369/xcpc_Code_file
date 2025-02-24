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
    set<ll> se;
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        se.insert(a[i]);
        ma[a[i]]++;
    }
    if (se.size() == 2)
    {
        vector<ll> ve;
        for (auto it : ma)
        {
            ve.push_back(it.second);
        }
        if (ve[0] == ve[1])
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
