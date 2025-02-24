#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
bool check(ll s1)
{
    bool res = 1;
    for (int i = 2; i * i <= s1; i++)
    {
        if (s1 % i == 0)
        {
            // cout << i << '\n';
            res = 0;
            break;
        }
    }
    return res;
}
ll get(ll s1)
{
    for (int i = 2; i <= s1; i++)
    {
        if (s1 % i == 0)
        {
            return i;
        }
    }
}
void solve()
{
    cin >> n;
    vector<ll> zs;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (check(a[i]))
        {
            zs.push_back(a[i]);
        }
    }
    if (zs.size() == 0)
    {
        cout << 2 << '\n';
        return;
    }
    if (zs.size() >= 2)
    {
        cout << -1 << '\n';
        return;
    }
    ll p = zs[0];
    for (int i = 1; i <= n; i++)
    {
        if (p == a[i])
        {
            continue;
        }
        if (a[i] % 2 == 0)
        {
            if (!(a[i] >= 2 * p))
            {
                cout << -1 << '\n';
                return;
            }
        }
        else
        {
            ll g = get(a[i]);
            if (!((a[i] - g) >= 2 * p))
            {
                cout << -1 << '\n';
                return;
            }
        }
    }
    cout << p << '\n';
    return;
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
// 没有质数 2
// 由质数 ->
// p->2p
//