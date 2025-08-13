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
        char c[105];
        cin >> c;
        ll len = 0;
        while (c[len] != '\0')
            len++;
        if ('a' <= c[0] && c[0] <= 'z')
        {
            c[0] -= 32;
        }
        for (int j = 1; j < len; j++)
        {
            if ('A' <= c[j] && c[j] <= 'Z')
            {
                c[j] += 32;
            }
        }
        cout << c << '\n';
    }
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