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
ll k;
struct node
{
    ll cnt, neg;
};
void solve()
{
    cin >> n >> k;
    map<ll, node> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i] + 1].neg++;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        ma[b[i] + 1].cnt--;
        ma[b[i] + 1].neg--;
    }
    ans = 0;
    ll num = n, ne = 0;
    for (auto [x, y] : ma)
    {
        if (ne <= k)
        {
            ans = max(ans, num * (x - 1));
        }
        num += y.cnt;
        ne += y.neg;
        if (ne <= k)
        {
            ans = max(ans, num * (x - 1));
        }
    }
    cout << ans << '\n';
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
