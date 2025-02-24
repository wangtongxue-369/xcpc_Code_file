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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    cin >> n >> m;
    char a[100][100];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    ans = 0;
    ll ai1, ai2, aj1, aj2;
    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int j1 = 1; j1 <= m; j1++)
        {
            for (int i2 = i1; i2 <= n; i2++)
            {
                for (int j2 = j1; j2 <= m; j2++)
                {
                    bool flag = 1;
                    for (int i = i1; i <= i2; i++)
                    {
                        for (int j = j1; j <= j2; j++)
                        {
                            if (a[i][j] == '*')
                            {
                                flag = 0;
                            }
                        }
                    }
                    if (flag == 1)
                    {
                        ll sum = (i2 - i1 + 1) * (j2 - j1 + 1);
                        if (sum > ans)
                        {
                            ai1 = i1;
                            ai2 = i2;
                            aj1 = j1;
                            aj2 = j2;
                            ans = sum;
                            // cout << ai1 << ' ' << aj1 << ' ' << ai2 << ' ' << aj2 << '\n';
                        }
                    }
                }
            }
        }
    }
    cout << ai1 << ' ' << aj1 << ' ' << ai2 << ' ' << aj2 << '\n';
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
