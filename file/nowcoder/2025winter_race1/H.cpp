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
    ll l, r;
    ll i;
    ll a = -1;
} a[MAXN];
bool cmp(node s1, node s2)
{
    if (s1.r == s2.r)
    {
        return s1.l < s2.l;
    }
    return s1.r < s2.r;
    // if (s1.l == s2.l)
    // {
    //     return s1.r < s2.r;
    // }
    // return s1.l < s2.l;
}
bool cmp2(node s1, node s2)
{
    return s1.i < s2.i;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i].i = i;
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1, a + 1 + n, cmp);
    set<ll> se;
    se.insert(1e9);
    for (int i = 1; i <= n; i++)
    {
        se.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        auto it = se.lower_bound(a[i].l);
        if (it == se.end() || *it > a[i].r)
        {
            cout << -1 << '\n';
            return;
        }
        a[i].a = *it;
        se.erase(it);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (a[i].a == -1)
    //     {
    //         cout << -1 << '\n';
    //         return;
    //     }
    // }
    sort(a + 1, a + 1 + n, cmp2);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].a << ' ';
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
