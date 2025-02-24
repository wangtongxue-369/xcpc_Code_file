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
ll _ = 1, n, m, ans = 0, k; // a[MAXN], f[MAXN];
inline ll read()
{
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}
vector<ll> a;
void solve()
{

    n = read(), m = read(), k = read();
    a.clear();
    for (int i = 1; i <= n; i++)
    {
        ll x = read();
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    ll l = 0;
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        while ((a[i] - a[l]) - (i - l) > k)
        {
            l++;
        }
        if (l >= n)
        {
            break;
        }
        ans = max(ans, i - l + 1 + k);
    }
    cout << min(ans, m) << '\n';
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
