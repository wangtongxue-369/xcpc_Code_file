#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 5050;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN][15][15];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll p = 1;
    ll lun = 1;
    ll last = 0;
    while (1)
    {
        ll sig = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= lun)
            {
                sig++;
            }
        }
        if (sig == 0)
        {
            break;
        }
        // cout << p << '\n';
        // cout << "!" << sig << '\n';
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= lun)
            {
                if (last == i)
                {
                    p++;
                }
                ll s = p;
                for (int j = 1; j <= 10; j++)
                {
                    f[i][lun][j] = s;
                    s += max(sig, 2ll);
                }
                p++;
                last = i;
            }
        }
        p = p - 1 + max(sig, 2ll) * 9 + 1;
        // cout << "hahaha" << p << '\n';
        lun++;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "#" << i << '\n';
        for (int j = 1; j <= a[i]; j++)
        {
            for (int w = 1; w <= 10; w++)
            {
                cout << f[i][j][w] << " \n"[(w == 10)];
            }
            // cout << " \n"[!(i == n && j == a[i])];
        }
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
