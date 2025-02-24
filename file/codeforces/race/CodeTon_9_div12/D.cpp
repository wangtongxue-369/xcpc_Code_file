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
ll _ = 1, n, m; // ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n >> m;
    vector<ll> s(m + 10);
    for (int i = 1; i <= m; i++)
    {
        cin >> s[i];
    }
    vector<ll> a(n + 10, 1e9);
    a[1] = m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2 * i; j <= n; j += i)
        {
            a[j] = min(a[i] - 1, a[j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= 0)
        {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << s[a[i]] << ' ';
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
