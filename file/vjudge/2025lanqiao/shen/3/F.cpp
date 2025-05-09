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
ll _ = 1, n, m, ans = 0, x[MAXN]; // a[MAXN], f[MAXN];
struct node
{
    ll x, y;
};
bool cmp(node s1, node s2)
{
    return s1.y < s2.y;
}
void solve()
{
    ll s, h, b;
    cin >> n >> s;
    cin >> h >> b;
    ll x, y;
    vector<node> a;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        if (x <= h + b)
        {
            a.push_back({x, y});
        }
    }
    sort(a.begin(), a.end(), cmp);
    ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (s >= a[i].y)
        {
            ans++;
            s -= a[i].y;
        }
        else
        {
            break;
        }
    }
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
