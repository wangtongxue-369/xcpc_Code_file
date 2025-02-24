#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 200005;
ll k;
ll _ = 1, n, m, q, ans = 0, a[N]; // f[500005];
struct node
{
    int l, r, i, ans;

    bool operator<(const node &x) const
    {
        if (l / k != x.l / k)
            return l < x.l;
        // 注意下面两行不能写小于（大于）等于，否则会出错（详见下面的小细节）
        if ((l / k) & 1)
            return r < x.r;
        return r > x.r;
    }
} b[N];
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

void solve()
{
    cin >> n >> q;
    k = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        // cin >> a[i];
        a[i] = read();
    }

    for (int i = 1; i <= q; i++)
    {
        b[i].i = i;
        // cin >> b[i].l >> b[i].r;
        b[i].l = read();
        b[i].r = read();
    }
    sort(b + 1, b + 1 + q);
    vector<int> ma(1e6 + 10);
    vector<ll> ans(q + 10);
    ll l = 1, r = 1, sumj = 1;
    ma[a[l]]++;
    for (int i = 1; i <= q; i++)
    {
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
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // cin >> _;
    _ = read();
    while (_--)
    {
        solve();
    }
    return 0;
}
