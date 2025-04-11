#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, f[MAXN][4];
string a[MAXN];
// f[i][0] 元音结尾
// f[i][1] 第一个辅音结尾
// f[i][2] 第二个辅音结尾
bool isy(char c)
{
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
    {
        return 1;
    }
    return 0;
}
void solve()
{
    memset(f, INF, sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    char c;
    f[1][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w < min(3ll, (ll)a[i].length()); w++)
        {
            if (isy(a[i][w]))
            {
                ll res = INF;
                for (int j = 0; j < 3; j++)
                {
                    res = min(res, f[i][j] + 1);
                }
                f[i][0] = res;
                f[i][1] = f[i][2] = INF;
            }
            else
            {
                f[i][2] = f[i][1] + 1;
                f[i][1] = f[i][0] + 1;
                f[i][0] = INF;
            }
            for (int j = 0; j < 3; j++)
            {
                f[i + 1][j] = min(f[i + 1][j], f[i][j]);
            }
        }
    }
    ll p = min({f[n + 1][0], f[n + 1][1], f[n + 1][2]});
    if (p >= 1e9)
    {
        cout << '*' << '\n';
    }
    else
    {
        cout << p << '\n';
    }
    // cout << min({f[n][0], f[n][1], f[n][2]}) << '\n';
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