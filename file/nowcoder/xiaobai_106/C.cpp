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
ll _ = 1, n, m, ans = 0, a[550][550], f[MAXN];
ll tx[] = {-1, 0, 1, 0};
ll ty[] = {0, -1, 0, 1};
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ll cnt1 = 0, cnt0 = 0;
            if (a[i][j] == 0)
            {
                continue;
            }
            for (int k = 0; k < 4; k++)
            {
                if (a[i + tx[k]][j + ty[k]] >= 0)
                {
                    cnt1++;
                }
                if (a[i + tx[k]][j + ty[k]] <= 0)
                {
                    cnt0--;
                }
            }
            if (a[i][j] < 0 && cnt1 == 4)
            {
                continue;
            }
            if (a[i][j] > 0 && cnt0 == -4)
            {
                continue;
            }
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
