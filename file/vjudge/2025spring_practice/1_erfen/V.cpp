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
ll prx = 0;
ll prp = 0;
ll ask(ll x)
{
    cout << "+ " << x << endl;
    cin >> x;
    return x;
}
void solve()
{
    cin >> n;
    ll l = 1, r = n;
    ll sum = 0;
    prp = 0;
    while (r - l > 1)
    {
        ll mid = (l + r) >> 1;
        ll p = ask(n - mid);
        if (p <= prp)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
        l = (l + n - mid) % n;
        r = (r + n - mid) % n;
        if (r == 0)
        {
            r = n;
        }
        prp = p;
    }
    cout << "! " << prp * n + l << endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    //  cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
