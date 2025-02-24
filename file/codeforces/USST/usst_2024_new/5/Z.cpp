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
ll _ = 1; // a[MAXN], f[MAXN];
struct node
{
    ll a, i;
};
ll p = 1e9 + 7;
bool cmp(node s1, node s2)
{
    if (s1.a == s2.a)
    {
        return s1.i > s2.i;
    }
    return s1.a < s2.a;
}
ll pow_quick(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}
ll C(ll n, ll m)
{
    if (m > n)
        return 0;
    ll ans = 1;
    for (ll i = 1; i <= m; i++)
    {
        ll a = (n + i - m) % p;
        ll b = i % p;
        ans = (ans * (a * pow_quick(b, p - 2) % p)) % p;
    }
    return ans;
}
ll Lucas(ll n, ll m)
{
    if (m == 0)
        return 1;
    else
        return (C(n % p, m % p) * Lucas(n / p, m / p)) % p;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<node> a(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a;
        a[i].i = i;
    }
    sort(a.begin() + 1, a.begin() + 1 + n, cmp);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i].a << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i].i << ' ';
    // }
    // cout << '\n';
    ll cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i].a == a[i + 1].a)
        {
            cnt++;
        }
        else if (a[i].i > a[i + 1].i)
        {
            cnt++;
        }
    }
    //__gcd(n,m);
    cout << Lucas(m + cnt, n) << '\n';
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
