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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll num;
    cin >> num;
    ll l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= num)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    if (a[l] != num)
    {
        cout << "meizhaodao\n";
        return;
    }
    cout << l << '\n';
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
