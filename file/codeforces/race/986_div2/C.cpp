#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 200005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN], pra[MAXN];
ll q[MAXN];
void solve()
{
    ll v;
    ll sumn = 0;
    cin >> n >> m >> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pra[i] = pra[i - 1] + a[i];
        sumn += a[i];
    }
    ll sum = 0;
    f[n + 1] = 0;
    map<ll, ll> maf, maq;
    for (int i = n; i >= 1; i--)
    {
        f[i] = f[i + 1];
        sum += a[i];
        if (sum >= v)
        {
            f[i]++;
            maf[f[i]] = i;
            sum = 0;
        }
    }
    ll p = 0;
    sum = 0;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        q[i] = q[i - 1];
        sum += a[i];
        if (sum >= v)
        {

            q[i]++;
            maq[q[i]] = i;
            sum = 0;
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << q[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << f[i] << ' ';
    // }
    // cout << '\n';
    if (maq.count(m) == 0)
    {
        cout << -1 << '\n';
        return;
    }
    ans = 0;
    bool flag = 0;
    maf[0] = n + 1;
    for (int i = 0; i <= m; i++)
    {
        ll l = maq[i], r = maf[m - i];
        // if (i == 2)
        // {
        //     cout << l << ' ' << r << '\n';
        // }

        if (maq.count(i) == 0)
        {
            continue;
        }
        if (maf.count(m - i) == 0)
        {
            continue;
        }
        if (r < l)
        {
            continue;
        }
        ans = max(ans, pra[r - 1] - pra[l]);
    }
    // i=m;
    // ans = max(ans, sumn - pra[m]);
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
