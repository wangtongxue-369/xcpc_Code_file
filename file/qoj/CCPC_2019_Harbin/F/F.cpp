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
    string s;
    map<ll, ll> ma[10];
    for (int i = 1; i <= 6; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            ma[i][s[j]]++;
        }
    }
    s = "harbin";
    ll sum = 1e10;
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
