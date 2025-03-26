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
    int n, k;
    char c;
    cin >> n >> c;
    k = sqrt((1 + n) / 2);
    for (int i = k; i >= 1; i--)
    {
        for (int j = 1; j <= k - i; j++)
        {
            cout << ' ';
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << c;
        }
        cout << '\n';
    }
    for (int i = 1; i <= k; i++)
    {
        if (i == 1)
            continue;
        for (int j = 1; j <= k - i; j++)
        {
            cout << ' ';
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << c;
        }
        cout << '\n';
    }
    cout << n - (2 * k * k - 1) << '\n';
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
