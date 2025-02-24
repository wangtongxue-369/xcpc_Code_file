#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '1' || s[s.length() - 1] == '1')
    {
        cout << "YES" << '\n';
        return;
    }
    for (int i = 0; i < s.length() - 1 - 1; i++)
    {
        if (s[i] == s[i + 1] && s[i] == '1')
        {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
