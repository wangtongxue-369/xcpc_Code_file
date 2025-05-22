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
    vector<ll> ve;
    for (auto it : s)
    {
        ve.push_back(it - '0');
    }
    sort(ve.begin(), ve.end());
    for (ll i = 9; i >= 0; i--)
    {
        auto it = lower_bound(ve.begin(), ve.end(), i);
        cout << *it;

        ve.erase(it);
    }
    cout << '\n';
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