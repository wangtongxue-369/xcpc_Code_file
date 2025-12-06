/*
 ASCII 略
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
ll ksm(ll a, ll b)
{
    ll r = 1;
    while (b)
    {
        if (b & 1)
            r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

const int MAXN = 500005;
ll c[MAXN], a[MAXN];

void solve()
{
    int n, k;
    cin >> n >> k;

    ll S = 0; // S = sum(c[i])
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        S += c[i];
        a[i] = c[i];
    }
    a[k] = c[k] + 1; // ★ a[k] corrected
    cout << S << '\n';
    // compute B = Σ a[i] / (S + a[i])
    ll B = 0;
    for (int i = 1; i <= n; i++)
    {
        ll den = (S + a[i]) % mod; // ★ correct denominator
        B = (B + a[i] % mod * ksm(den, mod - 2)) % mod;
    }
    // cout << B << '\n';
    ll one_minus_B = (1 - B + mod) % mod;
    ll inv_one_minus_B = ksm(one_minus_B, mod - 2);

    // answer = S / ( (1-B) * (S + a[k]) )
    ll den_k = (S + a[k]) % mod; // ★ correct denominator for k
    ll ans = S % mod;
    ans = ans * inv_one_minus_B % mod;
    ans = ans * ksm(den_k, mod - 2) % mod;

    // cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();
}
