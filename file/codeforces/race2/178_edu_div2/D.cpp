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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
const int L = 7000000; // 筛到700万
vector<ll> primes;
vector<ll> prefi;
void sieve()
{
    vector<bool> is_prime(L + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= L; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j <= L; j += i)
                is_prime[j] = false;
        }
    }
    prefi.push_back(0);
    for (ll p : primes)
    {
        prefi.push_back(prefi.back() + p);
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<ll>());
    vector<ll> prea(n + 10, 0);
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        prea[i] = prea[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (prea[i] >= prefi[i])
        {
            ans = i;
            // cout << ans << '\n';
            // return;
        }
        else
        {
            break;
        }
    }
    cout << n - ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}