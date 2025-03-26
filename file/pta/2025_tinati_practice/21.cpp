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
ll _ = 1, n, m, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    string s;
    // cin >> s;
    char c1;
    cin.get(c1);
    getline(cin, s);
    ll len = s.length();
    ll p = ceil(1.0 * len / n);
    string ans[200];
    ll s1 = 0;
    // cout << p << '\n';
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1 < s.length())
            {
                ans[j] = s[s1] + ans[j];
                s1++;
            }
            else
            {
                ans[j] = ' ' + ans[j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
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
