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
ll _ = 1, n, m, ans = 0, a[100][100], f[MAXN];
ll tx[] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
ll ty[] = {0, 3, 6, 0, 3, 6, 0, 3, 6};
void solve()
{
    n = 9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int w = 0; w < 9; w++)
    {
        map<ll, ll> ma;
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                ma[a[tx[w] + i][ty[w] + j]]++;
            }
        }
        for (auto it : ma)
        {
            if (it.second > 1 || !(1 <= it.first && it.first <= 9))
            {
                cout << 0 << '\n';
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        map<ll, ll> ma;
        for (int j = 1; j <= n; j++)
        {
            ma[a[i][j]]++;
        }
        for (auto it : ma)
        {
            if (it.second > 1 || !(1 <= it.first && it.first <= 9))
            {
                cout << 0 << '\n';
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        map<ll, ll> ma;
        for (int j = 1; j <= n; j++)
        {
            ma[a[j][i]]++;
        }
        for (auto it : ma)
        {
            if (it.second > 1 || !(1 <= it.first && it.first <= 9))
            {
                cout << 0 << '\n';
                return;
            }
        }
    }
    cout << 1 << '\n';
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
