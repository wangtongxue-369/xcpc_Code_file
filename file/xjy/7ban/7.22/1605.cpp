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
    char a[100000], b[100000];
    ll la = 0, lb = 0;
    cin >> a >> b;
    while (a[la] != '\0')
    {
        la++;
    }
    while (b[lb] != '\0')
    {
        lb++;
    }
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < la; i++)
    {
        if ('0' <= a[i] && a[i] <= '9')
        {
            s1 *= 10;
            s1 += a[i] - '0';
        }
    }
    for (int i = 0; i < lb; i++)
    {
        if ('0' <= b[i] && b[i] <= '9')
        {
            s2 *= 10;
            s2 += b[i] - '0';
        }
    }
    cout << s1 + s2 << '\n';
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