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
    ll k;
    cin >> n >> k;
    cin >> s;
    string t = s;
    for (int i = 0; i < s.length(); i++)
    {
        if (t[i] == '?')
        {
            t[i] = '0';
        }
    }

    ll p = 0, ji = 0;
    for (int i = 0; i < t.length() - 1; i++)
    {
        if (t[i] != t[i + 1])
        {
            p++;
        }
    }
    p = k - p;
    if (s[0] == '?')
    {
        ji++;
    }
    if (s[s.length() - 1] == '?')
    {
        ji++;
    }
    if (p == 0)
    {
        cout << t << '\n';
        return;
    }
    if (ji == 0 && (k - p))
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
