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
ll _ = 1, n, q, m, ans = 0, a[MAXN], l[MAXN], r[MAXN], t[MAXN];
ll tr[MAXN];
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        tr[i] += c;
    }
}
int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        res += tr[i];
    }
    return res;
}
bool check(ll x)
{
    for (int i = 1; i <= n; i++)
    {
        tr[i] = 0;
    }
    for (int i = 1; i <= x; i++)
    {
        add(t[i], 1);
    }
    ll len = 0, le = 0;
    for (int i = 1; i <= m; i++)
    {
        len = r[i] - l[i] + 1;
        le = sum(r[i]) - sum(l[i] - 1);
        if (le > len / 2)
        {
            return 1;
        }
    }
    return 0;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> t[i];
    }
    ll left = 1, right = q;
    while (left < right)
    {
        ll mid = (left + right) >> 1;
        if (check(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (left == q)
    {
        if (check(q))
        {
            cout << q << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
    else
    {
        cout << left << '\n';
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
