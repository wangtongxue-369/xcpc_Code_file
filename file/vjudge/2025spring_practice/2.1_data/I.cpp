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
    cin >> n;
    string s;
    cin >> s;
    ll p1 = 0, p2 = 0;
    stack<ll> st;
    for (int i = 0; i < s.length(); i++)
    {
        if ()
    }
    for (auto it : s)
    {
        if (it == ')')
        {
            p2++;
        }
    }
    // ans = 1e18;
    for (auto it : s)
    {
        if (it == '?')
        {
            continue;
        }
        if (it == '(')
        {
            p1++;
        }
        else
        {
            p2--;
        }
        ans = max(ans, min(p1, p2));
    }
    cout << 2 * ans << '\n';
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
