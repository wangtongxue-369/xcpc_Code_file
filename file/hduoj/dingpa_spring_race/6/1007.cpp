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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    s = ' ' + s;
    vector<ll> r, b;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'R')
        {
            r.push_back(a[i]);
        }
        else
        {
            b.push_back(a[i]);
        }
    }
    ll cs = min(r.size(), b.size());
    ans = 0;
    sort(r.begin(), r.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    for (int i = 0; i < cs; i++)
    {
        ans += r[i];
        ans += b[i];
    }
    if (cs == b.size() && cs < r.size())
    {
        ans += r[cs];
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