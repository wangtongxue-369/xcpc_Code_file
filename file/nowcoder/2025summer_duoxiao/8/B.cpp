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
ll A, B, C, U = (1 << 30) - 1;
ll f3, f2, f1, f;
ll g, h;
void init()
{
    f3 = A & U, f2 = B & U, f1 = C & U;
    for (int i = 0; i < n; i++)
    {
        g = f3 ^ (((1ll << 16) * f3) & U);
        h = g ^ (g / (1ll << 5));
        f = h ^ ((2 * h) & U) ^ f2 ^ f1;
        f3 = f2, f2 = f1, f1 = f;
        // cout << f << ' ';
    }
    // cout << '\n';
}
void get()
{
    g = f3 ^ (((1ll << 16) * f3) & U);
    h = g ^ (g / (1ll << 5));
    f = h ^ ((2 * h) & U) ^ f2 ^ f1;
    f3 = f2, f2 = f1, f1 = f;
}
void solve()
{
    cin >> n >> A >> B >> C;
    init();
    ll t, t1, t2;
    ll l, r, d;
    ans = 0;
    
    for (int i = 1; i < n; i++)
    {
        get();
        t = f;
        get();
        t1 = f;
        get();
        t2 = f;
        l = min(t % n, t1 % n);
        r = max(t % n, t1 % n);
        d = (t2 % n) + 1;
        // 区间长度奇数是不变 偶数变
        ll c = r - l + 1;
        if (c % 2 == 0)
        {
            if (d % 2 == 1)
            {
                if (ans == 1)
                {
                    ans = 0;
                }
                else
                {
                    ans = 1;
                }
            }
        }
        // cout << l << ' ' << r << ' ' << d << '\n';
        //  cout << ans << ' ';
    }
    // cout << '\n';
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