#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 200005;
ll k;
ll _ = 1, n, m, q, ans = 0, a[500005]; // f[500005];
struct node
{
    ll l, r;
    ll i;
    ll ans = 0;
} b[N];
bool cmp(node s1, node s2)
{
    if ((s1.l / k) == (s2.l / k))
    {
        return (s1.r / k) < (s2.r / k);
    }
    return (s1.l / k) < (s2.l / k);
}
bool cmp1(node s1, node s2)
{
    if ((s1.l / k) == (s2.l / k))
    {
        return (s1.r) < (s2.r);
    }
    return (s1.l / k) < (s2.l / k);
}
bool cmp2(node s1, node s2)
{
    return s1.i < s2.i;
}
void solve()
{
    cin >> n >> q;
    k = ceil(sqrt(n));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        b[i].i = i;
        cin >> b[i].l >> b[i].r;
    }
    sort(b + 1, b + 1 + q, cmp1);
    vector<int> ma(1e6 + 10);
    vector<ll> ans(q + 10);
    ll l = 1, r = 1, sumj = 1;
    ma[a[l]]++;
    for (int i = 1; i <= q; i++)
    {
        while (r < b[i].r)
        {
            r++;
            ma[a[r]]++;
            if (ma[a[r]] % 2)
            {
                sumj++;
            }
            else
            {
                sumj--;
            }
        }

        while (b[i].l < l)
        {
            l--;
            ma[a[l]]++;
            if (ma[a[l]] % 2)
            {
                sumj++;
            }
            else
            {
                sumj--;
            }
        }

        while (l < b[i].l)
        {

            ma[a[l]]--;
            if (ma[a[l]] % 2)
            {
                sumj++;
            }
            else
            {
                sumj--;
            }
            l++;
        }
        while (b[i].r < r)
        {
            ma[a[r]]--;
            if (ma[a[r]] % 2)
            {
                sumj++;
            }
            else
            {
                sumj--;
            }
            r--;
        }
        ans[b[i].i] = sumj;
        // b[i].ans = sumj;
    }
    for (int i = 1; i <= q; i++)
    {
        if (ans[i] >= 1)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
    }
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