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
    string s;
    cin >> n;
    cin >> s;
    // cout << s.substr(2, 2) << '\n';
    map<ll, ll> ma;
    ans = 0;
    for (int i = 2; i < s.length(); i++)
    {
        ma[s[i - 2]]++;
        if ((i + 8 - 1) < s.length())
        {
            if ("uwawauwa" == s.substr(i, 8))
            {
                ans += ma['u'];
            }
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
