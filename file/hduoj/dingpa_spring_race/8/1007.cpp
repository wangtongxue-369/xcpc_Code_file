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
    ll p, q;
} a[MAXN], b[MAXN];
ll t = 0;
void solve()
{
    ll n1, n2;
    cin >> n1 >> n2;
    set<ll> se;
    ll la = 0;
    ans = 0;
    for (int i = 1; i <= n1; i++)
    {
        cin >> a[i].p >> a[i].q;
        a[i].p *= (t / a[i].q);
        se.insert(la);
        la += a[i].p;
    }
    la = 0;
    for (int i = 1; i <= n2; i++)
    {
        cin >> b[i].p >> b[i].q;
        b[i].p *= (t / b[i].q);
        if (se.count(la))
        {
            ans++;
        }
        la += b[i].p;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << __gcd(1, __gcd(2, __gcd(3, __gcd(4, __gcd(6, __gcd(8, 16)))))) << '\n';
    //  cout << __gcd({1, 2, 3, 4, 6, 8, 16}) << '\n';
    t = 1 * 2 * 3 * 4 * 6 * 8 * 16;
    // cout << t << '\n';
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}