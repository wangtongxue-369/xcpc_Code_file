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
ll _ = 1, n, m, ans = 0, f[MAXN];
struct node
{
    ll v, i;
    bool operator<(const node &other) const
    {
        if (v != other.v)
            return v < other.v;
        return i > other.i;
    }
};
void solve()
{
    ll k;
    cin >> n >> k;
    vector<vector<node>> a(k);
    ll x;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i % k].push_back({x, i});
    }
    for (int i = 0; i < k; i++)
    {
        sort(a[i].begin(), a[i].end());
    }
    ll p = -1, i = 0;
    while (1)
    {
        x = i % k;
        if (p == n - 1)
        {
            break;
        }
        while (!a[x].empty() && a[x].back().i < p)
        {
            a[x].pop_back();
        }
        if (!a[x].empty())
        {
            cout << a[x].back().v << ' ';
            p = a[x].back().i;
            a[x].pop_back();
        }
        i++;
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
