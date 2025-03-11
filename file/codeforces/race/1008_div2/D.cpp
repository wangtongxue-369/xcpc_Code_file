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
    char c1, c2;
    ll s1, s2;
} a[500];
ll f[500];
ll get(char c, ll x, ll sum)
{
    if (c == '+')
    {
        return x + sum;
    }
    else
    {
        return x * sum;
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].c1 >> a[i].s1 >> a[i].c2 >> a[i].s2;
    }
    ll l = 1, r = 1;
    ll ew = 0;
    for (int i = 1; i <= n; i++)
    {
        ll sum1 = get(a[i].c1, a[i].s1, l);
        ll sum2 = get(a[i].c2, a[i].s2, r);
        ll sumleft = get(a[i].c1, a[i].s1, ew);
        ll sumright = get(a[i].c2, a[i].s2, ew);
        if (a[i].c1 == a[i].c2 && a[i].c1 == '+')
        {
            ew += a[i].s1 + a[i].s2;
            continue;
        }
        if (a[i].c1 == a[i].c2 && a[i].c1 == 'x')
        {
            if (a[i].s1 > a[i].s2)
            {
                l += ew;
                ew = get(a[i].c1, a[i].s1, l) - l + get(a[i].c2, a[i].s2, r) - r;
                continue;
            }
            if (a[i].s1 < a[i].s2)
            {
                r += ew;
                ew = get(a[i].c1, a[i].s1, l) - l + get(a[i].c2, a[i].s2, r) - r;
                continue;
            }
            if (a[i].s1 == a[i].s2)
            {
                ew *= a[i].s1;
                ew += sum1 - l + sum2 - r;
                continue;
            }
            continue;
        }
        {
            if (a[i].c1 == 'x')
            {
                l += ew;
                ew = get(a[i].c1, a[i].s1, l) - l + sum2 - r;
            }
            else
            {
                r += ew;
                ew = sum1 - l + get(a[i].c2, a[i].s2, r) - r;
            }
        }
    }
    cout << ew + l + r << '\n';
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
