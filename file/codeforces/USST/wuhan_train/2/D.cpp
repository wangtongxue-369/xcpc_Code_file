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
} a[MAXN];
bool cmp1(node s1, node s2)
{
    return s1.w < s2.w;
}
bool cmp2(node s1, node s2)
{
    return s1.v + s1.w < s2.v + s2.w;
}
bool check(ll x)
{
    vector<node> v1, v2;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].v < x)
        {
            v1.push_back(a[i]);
        }
        else
        {
            v2.push_back(a[i]);
        }
    }
    sort(v1.begin(), v1.end(), cmp1);
    sort(v2.begin(), v2.end(), cmp2);
    ll p1 = 0, p2 = 0;
    while (p1 < v1.size() && p2 < v2.size())
    {
        if (v2[p2].v + v2[p2].w - v1[p1].w >= x)
        {
            p1++, p2++;
        }
        else
        {
            p2++;
        }
    }
    if (p1 == v1.size())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void solve()
{
    cin >> n;
    ll l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].v >> a[i].w;
        r = max(r, a[i].v);
    }
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l << '\n';
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
