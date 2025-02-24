#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 1e6 + 100;
ll _ = 1, n, m, x, ans = 0; // a[MAXN], f[MAXN];
ll op[MAXN];
struct node
{
    ll n;
    vector<ll> a;
} a[MAXN];
struct node2
{
    ll x, y;
} add[MAXN];
vector<ll> dp(MAXN + 10, 0);
inline ll read()
{
    ll x = 0, f = 1;
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
    n = read();
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        a[i].a.clear();
        op[i] = read();
        if (op[i] == 1)
        {
            a[i].n = read();
            for (int j = 1; j <= a[i].n; j++)
            {
                x = read();
                a[i].a.push_back(x);
            }
        }
        else
        {
            add[i].x = read();
            add[i].y = read();
        }
    }
    ll len = 0;
    map<ll, ll> ma;
    dp[n] = 1;
    for (int i = n; i >= 1; i--)
    {
        if (op[i] == 2)
        {
            dp[add[i].x] += dp[i];
            dp[add[i].y] += dp[i];
        }
        else
        {
            for (int j = 0; j < a[i].a.size(); j++)
            {
                ma[a[i].a[j]] += dp[i];
            }
            len += a[i].a.size() * dp[i];
        }
    }
    ll maxn = 0;
    for (auto it : ma)
    {
        maxn = max(maxn, it.second);
    }
    if (maxn > len - maxn)
    {
        cout << 2 * (len - maxn) << '\n';
    }
    else
    {
        cout << len << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    _ = read();
    while (_--)
    {
        solve();
    }
    return 0;
}
