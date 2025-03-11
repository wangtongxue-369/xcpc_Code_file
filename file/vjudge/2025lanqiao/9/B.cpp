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
bool cmp(char s1, char s2)
{
    return s1 > s2;
}
void solve()
{
    ll x, k;
    string s;
    cin >> s >> k;
    while (k--)
    {
        sort(s.begin(), s.end());
        ll c1 = 0, c2 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            c1 = c1 * 10 + (s[s.length() - i - 1] - '0');
            c2 = c2 * 10 + (s[i] - '0');
        }
        c1 = abs(c1 - c2);
        s = to_string(c1);
    }
    cout << s << '\n';
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
