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
string s[1010];
void solve()
{
    cin >> n >> m;
    vector<ll> ve;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];

        // ve.push_back(s[i].length());
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i].length() <= m)
        {
            m -= s[i].length();
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
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
