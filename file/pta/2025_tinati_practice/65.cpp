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
    ans = 0;
    // string s1;
    vector<ll> s1;
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        s1.push_back(x);
    }
    vector<ll> tails;
    for (auto num : s1)
    {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end())
        {
            tails.push_back(num);
        }
        else
        {
            *it = num;
        }
    }
    cout << tails.size() << '\n';
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