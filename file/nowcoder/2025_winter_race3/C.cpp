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
string s[MAXN];
bool cmp(string s1, string s2)
{
    return s1 < s2;
}
void solve()
{
    cin >> n >> m;
    ans = 0;
    ll mlen = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        mlen = max(mlen, (ll)s[i].length());
        ans += 2 * s[i].length();
    }
    sort(s + 1, s + 1 + n, cmp);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << s[i] << '\n';
    // }
    a[1] = s[1].length();
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < min(s[i - 1].length(), s[i].length()); j++)
        {
            if (s[i - 1][j] == s[i][j])
            {
                ans -= 2;
                continue;
            }
            else
            {
                break;
            }
        }
    }
    ll l, r;
    while (m--)
    {
        cin >> l >> r;
        cout << ans - mlen << '\n';
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
