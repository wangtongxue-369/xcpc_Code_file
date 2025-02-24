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
    ll sumj = 0, sumo = 0;
    ll ji = 0, ou = 0;
    for (int i = 1; i <= n; i += 2)
    {
        ji++;
        sumj += a[i];
    }
    for (int i = 2; i <= n; i += 2)
    {
        ou++;
        sumo += a[i];
    }
    if (sumj % ji == 0 && sumo % ou == 0 && sumj / ji == sumo / ou)

    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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
