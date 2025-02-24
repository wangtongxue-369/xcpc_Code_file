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
string s[MAXN];
void solve()
{
    cin >> n >> m;
    ll len = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        len = max(len, (ll)s[i].length());
    }
    ll sum = 0;
    for (int i = 0; i < len; i++)
    {

        set<ll> se;
        for (int j = 1; j <= n; j++)
        {
            if (i == 1)
            {
                cout << s[j][i] << ' ';
            }
            if (i < s[j].length())
            {
                se.insert(s[j][i]);
            }
        }
        sum += 2 * se.size();
        // cout << i << ' ' << se.size() << '\n';
    }
    ll l, r;
    while (m--)
    {
        cin >> l >> r;
        cout << sum - len << '\n';
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
