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
    set<int> se;
    for (int i = 1; i <= 2000050; i++)
    {
        se.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        se.erase(se.find(a[i]));
    }
    cin >> m;
    ll x, tmp;
    while (m--)
    {
        cin >> x;
        auto it = se.upper_bound(a[x]);
        cout << *it << " \n"[m != 0];
        tmp = a[x];
        a[x] = *it;
        se.erase(it);
        se.insert(tmp);
    }
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