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
ll _ = 1, n, m, a[MAXN], f[MAXN];
void solve()
{
    cin >> n >> m;
    if (m > (n - 1) * n / 2)
    {
        cout << "NO\n";
        return;
    }
    // 最大可以有(n-1)*n/2
    // 最小呢？就是每一行尽量填
    vector<ll> dep(n + 10);
    vector<vector<ll>> nu(n + 10);
    ll maxd = 0;
    for (int i = 2; i <= n; i++)
    {
        dep[i] = dep[i >> 1] + 1;
        nu[dep[i]].push_back(i);
        m -= dep[i];
        maxd = max(maxd, dep[i]);
    }
    for (int i = 1; i <= maxd; i++)
    {
        for (auto it : nu[i])
        {
            // cout << it << ' ';
        }
        // cout << '\n';
    }
    if (m < 0)
    {
        cout << "NO\n";
        return;
    }
    while (m)
    {
        for (int i = 1; i <= maxd; i++)
        {
            // （当前行的数量-1）*2 >=下一行+1
            if ((nu[i].size() - 1) * 2 >= (nu[i + 1].size() + 1))
            {
                nu[i + 1].push_back(nu[i].back());
                nu[i].pop_back();
                if (i == maxd)
                {
                    maxd++;
                }
                break;
            }
        }
        m--;
    }
    cout << "YES\n";
    vector<ll> fa(n + 10);
    nu[0].push_back(1);
    for (int i = 1; i <= maxd; i++)
    {
        for (int j = 0; j < nu[i].size(); j++)
        {
            fa[nu[i][j]] = nu[i - 1][j >> 1];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        cout << fa[i] << ' ';
    }
    cout << '\n';
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