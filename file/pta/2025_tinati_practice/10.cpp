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
    string s;
    cin >> s;
    int num2 = 0;
    int count2 = 0;
    double p1 = 1.0, p2 = 1.0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '2')
        {
            count2++;
        }
    }
    if (s[0] == '-')
    {
        p1 += 0.5;
    }

    if (s[s.length() - 1] % 2 == 0)
    {
        p2 += 1;
    }

    if (s[0] == '-')
    {
        printf("%.2f%%", 1.0 * count2 / (s.length() - 1) * p1 * p2 * 100);
    }
    else
    {
        printf("%.2f%%", 1.0 * count2 / s.length() * p1 * p2 * 100);
    }

    return;
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
