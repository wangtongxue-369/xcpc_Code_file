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
    ll k;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    a[n]--;
    sort(a + 1, a + 1 + n);
    ll d = a[n] - a[1];
    if (d > k)
    {
        cout << "Jerry\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
    }
    if (sum % 2 == 0)
    {
        cout << "Tom\n";
    }
    else
    {
        cout << "Jerry\n";
    }
}

// 最大值-最小值>k
//
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