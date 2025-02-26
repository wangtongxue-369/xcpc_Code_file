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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ans = 0;
    ll ansl = 1, ansr = 1;
    for (int l = 1; l <= n; l++)
    {
        ll da = 0, xiao = 0;
        for (int r = l + 1; r <= n; r++)
        {
            if (a[r] > a[l])
            {
                da++;
            }
            if (a[r] < a[l])
            {
                xiao++;
            }
            if (xiao > da && (xiao - da) > ans)
            {
                ans = (xiao - da);
                ansl = l;
                ansr = r;
            }
        }
    }
    cout << ansl << ' ' << ansr << '\n';
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
