/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll fact[200005], invFact[200005];
ll power(ll base, ll exp)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void prec(int n)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    invFact[n] = power(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
}

long long nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return (((fact[n] * invFact[r]) % mod) * invFact[n - r]) % mod;
}
void solve()
{
    cin >> n;
    vector<ll> da(n + 10, 0), db(n + 10, 0), dc(n + 10, 0);

    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        ll al = l, ar = r;
        ll bl = n - r, br = n - l;

        if (max(al, bl) > min(ar, br))
        {
            da[max(1ll, al)]++;
            da[min(n, ar + 1)]--;
            db[max(1ll, bl)]++;
            db[min(n, br + 1)]--;
        }
        else
        {
            ll il = max(al, bl), ir = min(ar, br);
            if (al < il)
            {
                da[max(1ll, al)]++;
                da[min(n, il)]--;
            }
            if (ar > ir)
            {
                da[max(1ll, ir + 1)]++;
                da[min(n, ar + 1)]--;
            }
            if (bl < il)
            {
                db[max(1ll, bl)]++;
                db[min(n, il)]--;
            }
            if (br > ir)
            {
                db[max(1ll, ir + 1)]++;
                db[min(n, br + 1)]--;
            }
            dc[max(1ll, il)]++;
            dc[min(n, ir + 1)]--;
        }
    }
    ll ca = 0, cb = 0, cc = 0;
    for (int i = 1; i <= n; i++)
    {
        ca += da[i];
        cb += db[i];
        cc += dc[i];
        if (ca + cb + cc != n)
        {
            continue;
        }
        ans = (ans + nCr(cc, i - ca)) % mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    prec(200002);
    while (_--)
    {
        solve();
    }
    return 0;
}