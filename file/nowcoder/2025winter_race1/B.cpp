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
ll rdu[MAXN], cdu[MAXN], du[MAXN];

bool flag = 0;
void solve()
{
    cin >> n;
    ll u, v;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        cdu[u]++;
        rdu[v]++;
        du[u]++;
        du[v]++;
    }
    vector<ll> ve;
    ll tag = 0, sum = 0, sum0 = 0;
    ;
    for (int i = 1; i <= n; i++)
    {
        if (du[i] == 0)
        {
            sum0++;
        }
        if (du[i] == 1)
        {
            ve.push_back(i);
            sum++;
        }
        if (du[i] >= 3)
        {
            tag = -1;
            break;
        }
    }
    if (tag == -1)
    {
        cout << -1 << '\n';
        return;
    }
    if (sum == 2 && sum0 == 0)
    {
        cout << ve[0] << ' ' << ve[1] << '\n';
    }
    else
    {
        cout << -1 << '\n';
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
