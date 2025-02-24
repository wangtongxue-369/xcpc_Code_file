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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
ll x;

int 计数器 = 0;

vector<ll> a;
ll work1()
{
    vector<ll> dp(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
    }
}
void solve()
{

    while (cin >> x)
    {
        a.push_back(x);
    }
    n = a.size();
    cout << work1() << '\n';
    ll l = 1, r = n;
    while (l < r)
    {
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
