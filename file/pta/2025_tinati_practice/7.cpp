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
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    set<char> se;
    for (auto it : s2)
    {
        se.insert(it);
    }
    for (auto it : s1)
    {
        if (se.contains(it))
        {
            continue;
        }
        else
        {
            cout << it;
        }
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
