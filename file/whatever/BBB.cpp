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
    n = 4;
    vector<ll> ve;
    for (int i = 0; i < n; i++)
    {
        ve.push_back(i);
    }
    while (next_permutation(ve.begin(), ve.end()))
    {
        for (auto it : ve)
        {
            cout << it << ' ';
        }
        cout << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}