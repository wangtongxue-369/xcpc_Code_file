#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
struct node
{
    ll l, r, w;
};
void solve()
{
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ll j = 0;
    ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        j = max(i, j);
        while (j + 1 <= n && a[j + 1] - a[j] <= 1 && a[j + 1] - a[i] < k)
        {
            j++;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
