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
    ll maxn = 0;
    ll minn = 1e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        minn = min(minn, a[i]);
        maxn = max(maxn, a[i]);
    }
    // sort(a + 1, a + 1 + n);
    if (minn == maxn)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == maxn)
        {
            cout << 2 << ' ';
        }
        else
        {
            cout << 1 << ' ';
        }
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