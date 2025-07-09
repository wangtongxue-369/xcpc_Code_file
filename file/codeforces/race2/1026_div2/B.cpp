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
    ll tmp = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == '(')
        {
            tmp++;
        }
        if (s[i] == ')')
        {
            tmp--;
        }
        if (tmp == 0)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
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