#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll MAXN = 200005;
const ll base1 = 131;
const ll base2 = 127;
int _ = 1, n, m, a[MAXN], f[MAXN];
int tree[MAXN];
// vector<ll> f(MAXN,0);
int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int k)
{
    x++;
    while (x <= m)
    {
        tree[x] += k;
        x += lowbit(x);
    }
}
int getsum(int x)
{
    x++;
    int res = 0;
    while (x > 0)
    {
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // sl sr 对于每个r，需要他左侧有多少个sl比他大
    for (int i = 1; i <= n; i++)
    {
        a[i] = (a[i - 1] + a[i]) % m;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans + 1ll * a[i] * i;
    }
    ll sum = a[1];
    for (int i = 2; i <= n; i++)
    {
        ans -= sum;
        sum = sum + 1ll * a[i];
    }
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (i - 1 - getsum(a[i]));
        add(a[i], 1);
    }
    ans += sum * m * 1ll;
    cout << ans << '\n';
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
