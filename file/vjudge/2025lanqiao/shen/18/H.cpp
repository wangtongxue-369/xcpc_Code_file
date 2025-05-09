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
struct node
{
    ll v, w;
    bool operator<(node &t)
    {

        return v + w < t.v + t.w;
    }

} a[MAXN];
ll w[MAXN], v[MAXN];
ll f[20010];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].w >> a[i].v;
    }
    sort(a + 1, a + 1 + n);
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i].v; j >= 0; j--)
        {
            f[j + a[i].w] = max(f[j + a[i].w], f[j] + a[i].v);
            ans = max(ans, f[j + a[i].w]);
        }
    }
    cout << ans << '\n';
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
