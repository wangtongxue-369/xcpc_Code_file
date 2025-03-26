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
    ll s1, s2, f = 1;
} a[MAXN];
ll lcm(ll s1, ll s2)
{
    return s1 * s2 / __gcd(s1, s2);
}
void solve()
{
    ll s1 = 0, s2 = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        char c;
        cin >> a >> c >> b;
        s1 = s1 * b + s2 * a;
        s2 = s2 * b;
        int d = gcd(s1, s2);
        s1 /= d;
        s2 /= d;
    }
    ll sumint = s1 / s2;
    s1 %= s2;
    if (sumint && s1)
    {
        cout << sumint << ' ' << s1 << '/' << s2;
    }
    else if (sumint)
    {
        cout << sumint;
    }
    else
    {
        if (!s1)
        {
            cout << '0';
        }
        else
        {
            cout << s1 << '/' << s2;
        }
        }
    return;
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
