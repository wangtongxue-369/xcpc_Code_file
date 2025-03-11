#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 100005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, u[MAXN][4]; // v[MAXN], w[MAXN];
ll pir[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
void solve()
{
    cin >> n;
    vector<set<ll>> ma(n + 10);
    ll x1, x2, x3, x4, x5, x6, x;
    ll a, b, c;
    for (int i = 1; i <= n; i++)
    {
        cin >> u[i][0] >> u[i][1] >> u[i][2];
        for (int w = 0; w < 6; w++)
        {
            a = u[i][pir[w][0]];
            b = u[i][pir[w][1]];
            c = u[i][pir[w][2]];
            if ((c - b) % a == 0 && ((c - b) / a) >= 0)
            {
                ma[i].insert((c - b) / a);
            }
        }
    }

    for (auto it : ma[1])
    {
        bool flag = 1;
        for (int i = 2; i <= n; i++)
        {
            if (!ma[i].contains(it))
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout << it << '\n';
            return;
        }
    }
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
