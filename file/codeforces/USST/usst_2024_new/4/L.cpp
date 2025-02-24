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
struct node
{
    ll s;
    ll i;
};
bool cmp(node s1, node s2)
{
    return s1.s < s2.s;
}
void solve()
{
    ll k;
    cin >> n >> k;
    vector<node> ve;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        node x;
        x.s = a[i];
        x.i = i;
        ve.push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    ll k1 = 0;
    vector<ll> v;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= b[i])
        {
            ans += a[i];
            k1++;
        }
        else
        {
            ans += b[i];
            v.push_back(a[i] - b[i]);
        }
    }
    if (k1 >= k)
    {
        cout << ans << '\n';
    }
    else
    {
        sort(v.begin(), v.end());
        for (int i = 0; i < k - k1; i++)
        {
            ans += v[i];
        }
        cout << ans << '\n';
    }
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
