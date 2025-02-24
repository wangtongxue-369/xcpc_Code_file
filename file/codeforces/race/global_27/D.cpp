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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
ll f[MAXN];
ll qsm(ll pa, ll pb)
{
    ll res = 1;
    while (pb)
    {
        if (pb & 1)
        {
            res = res * pa % mod;
        }
        pa = pa * pa % mod;
        pb >>= 1;
    }
    return res;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ans = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    for (int i = 1; i <= n; i++)
    {
        int c = 0;
        while (a[i] % 2 == 0)
        {
            a[i] /= 2;
            c++;
        }
        while (!q.empty() && log2(a[i]) + c - log2(q.top().first) > 0)
        {
            auto [x0, c0] = q.top();
            // ans=(ans-(x0*qsm(2,c0)))
            ans = ((ans - (x0 * qsm(2, c0)) % mod) + mod) % mod;
            ans = (ans + x0) % mod;
            // ans = ans - x0 * qsm(2, c0) + x0;
            c += c0;
            q.pop();
        }
        q.emplace(a[i], c);
        // ans = ans + a[i] * qsm(2, c);
        ans = (ans + a[i] * qsm(2, c) % mod) % mod;
        cout << ans << ' ';
    }
    cout << '\n';
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
// 对于任意一个偶数，如果后面有大于他的数他一定是贡献给后面的
// 对于i 他应该把自己可以的贡献全部转移到后面
