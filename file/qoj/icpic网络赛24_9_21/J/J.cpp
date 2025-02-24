#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 100005;
ll _ = 1, n, m, ans = 0; // a[500005], f[500005];
struct node
{
    ll w, v, c;
} a[N];
bool cmp(node s1, node s2)
{
    double ss1 = (1.0 * s1.c / (1.0 * s1.w));
    double ss2 = (1.0 * s2.c / (1.0 * s2.w));
    return ss1 < ss2;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].w >> a[i].v >> a[i].c;
    }
    sort(a + 1, a + 1 + n, cmp);
    ll sum = 0;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i].v - sum * a[i].c;
        sum += a[i].w;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
