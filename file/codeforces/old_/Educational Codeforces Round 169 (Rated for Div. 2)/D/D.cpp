#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
map<string, vector<ll>> ma;
void solve()
{
    cin >> n >> q;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        ma[s].push_back(i);
        s.reserve();
        ma[s].push_back(i);
    }
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
