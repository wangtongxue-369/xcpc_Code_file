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
    ll x;
    cin >> n >> x;
    vector<ll> ve;
    ll p = 0;
    ll sum = 0;
    ll y;
    for (ll i = 0; i <= 32; i++)
    {
        if (x & (1ll << i))
        {
            sum += (1ll << i);
            p = i;
            continue;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < min(n, sum + 1); i++)
    {
        ve.push_back(i);
    }
    while (ve.size() < n)
    {
        ve.push_back(0);
    }
    ll s = ve[0];
    for (int i = 1; i < ve.size(); i++)
    {
        s |= ve[i];
    }
    if (s != x)
    {
        ve[ve.size() - 1] = x;
    }
    for (auto it : ve)
    {
        cout << it << ' ';
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
