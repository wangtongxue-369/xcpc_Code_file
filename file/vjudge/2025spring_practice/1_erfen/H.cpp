#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000050;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0;
PII a[MAXN];
void solve()
{
    cin >> n >> m;
    ll p;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> p;
            a[p] = {i, j};
        }
    }
    ll l = 0, r = n * m;
    std::function<bool(ll x)> check = [&](ll x)
    {
        vector<PII> ve;
        for (int i = 0; i < x; i++)
        {
            ve.push_back(a[i]);
        }
        sort(ve.begin(), ve.end());
        ll e = 0;
        for (auto [i, j] : ve)
        {
            if (j >= e)
            {
                e = j;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    };
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l << '\n';
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
