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
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
void solve()
{
    ll b;
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ji = 0, ou = 0;
    vector<ll> ve;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 1)
        {
            ji++;
        }
        else
        {
            ou++;
        }
        if (ji == ou && ji != 0 && i != n)
        {
            ve.push_back(abs(a[i] - a[i + 1]));
        }
    }
    sort(ve.begin(), ve.end());
    ll sum = 0;
    for (auto it : ve)
    {
        if (sum + it <= b)
        {
            sum += it;
            ans++;
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
