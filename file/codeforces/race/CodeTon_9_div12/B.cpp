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
    cin >> s;
    if (s.length() == 1)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            cout << s[i] << s[i] << '\n';
            return;
        }
    }
    for (int i = 0; i < s.length() - 2; i++)
    {
        if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2])
        {
            cout << s[i] << s[i + 1] << s[i + 2] << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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
// 两个相同
// 三个不同
