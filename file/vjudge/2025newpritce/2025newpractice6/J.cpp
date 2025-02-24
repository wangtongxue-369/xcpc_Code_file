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
ll _ = 1, n, m, ans = 0; // x[MAXN], a[MAXN];
struct node
{
    ll x, a;
} a[MAXN];
bool cmp(node s1, node s2)
{
    return s1.x < s2.x;
}
void solve()
{
    cin >> n >> m;
    ll sum = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].x;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].a;
        sum += a[i].a;
    }
    sort(a + 1, a + 1 + m, cmp);
    a[m + 1].x = n + 1;
    if (sum != n || a[1].x != 1)
    {
        cout << -1 << '\n';
        return;
    }
    ans = 0;
    ll res = 0;
    for (int i = 1; i <= m; i++)
    {
        ll len = a[i + 1].x - a[i].x - 1;
        if (len > a[i].a - 1)
        {
            cout << -1 << '\n';
            return;
        }
        else
        {
            ans += (1 + len) * len / 2;
            ans += (len + 1) * (a[i].a - 1 - len);
            a[i + 1].a += a[i].a - len - 1;
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
