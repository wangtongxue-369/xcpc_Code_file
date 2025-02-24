#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1050;
const ll base1 = 131;
const ll base2 = 127;
vector<PII> ans;
ll _ = 1, n, m, a[MAXN], f[MAXN];
void ask(ll s1, ll s2)
{
    ll s;
    cout << '?' << ' ' << s1 << ' ' << s2 << endl;
    cin >> s;
    if (s1 == s || s2 == s)
    {
        ans.push_back({s1, s2});
    }
    else
    {
        ask(s, s2);
    }
}
void solve()
{
    cin >> n;
    vector<ll> ve;
    ans.clear();
    for (int i = 1; i < n; i++)
    {
        ask(n, i);
    }
    cout << "! ";
    for (auto it : ans)
    {
        cout << it.first << ' ' << it.second << ' ';
    }
    cout << endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
