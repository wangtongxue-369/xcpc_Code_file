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
ll _ = 1, n, m, ans = 0;
struct node
{
    ll a, b;
} a[MAXN];
bool cmp(node s1, node s2)
{
    return s1.a < s2.a;
}
void solve()
{
    ll k;
    cin >> n >> k;
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a >> a[i].b;
        ma[a[i].a] += a[i].b;
    }
    ll d = 0;
    ll sum = 0;
    for (auto it : ma)
    {
        sum += (it.first - d) * k;
        d = it.first;
        if (sum >= it.second)
        {
            sum -= it.second;
        }
        else
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
