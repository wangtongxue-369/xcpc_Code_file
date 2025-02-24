#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    string s, r;
    cin >> s >> r;
    ll sum0 = 0, sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            sum1++;
        }
        else
        {
            sum0++;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {

        if (sum1 <= 0 || sum0 <= 0)
        {
            cout << "NO\n";
            return;
        }
        else
        {
            if (r[i] == '1')
            {
                sum0--;
            }
            else
            {
                sum1--;
            }
        }
    }
    cout << "YES\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
