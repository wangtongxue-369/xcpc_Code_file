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
const ll MA = 100005;
ll _ = 1, n, m, ans = 0, fa[MAXN];
ll find(ll x)
{
    if (fa[x] != x)
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void unio(ll s1, ll s2)
{
    ll t1 = find(s1), t2 = find(s2);
    if (t1 != t2)
    {
        fa[t1] = t2;
    }
}
ll prime[MA];
bool f[MA];
ll cnt = 0;
ll p;
ll a;
void Prime(ll n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!f[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                f[j] = 1;
                if (i >= p && j - i >= a)
                {
                    unio(j, j - i);
                }
            }
        }
    }
}
void solve()
{
    ll b;
    cin >> a >> b >> p;
    for (int i = a; i <= b; i++)
    {
        fa[i] = i;
    }
    Prime(b);

    set<ll> se;
    for (int i = a; i <= b; i++)
    {
        se.insert(find(i));
    }
    cout << se.size() << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}