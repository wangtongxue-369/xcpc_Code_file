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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    string s;
    ll a;
    cin >> n >> a >> s;
    ll sum = 0;
    bool f1 = 0, f2 = 0;
    ll g = 0, k = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            sum++;
        }
        if (s[i] == '0')
        {
            g++;
            if (g >= a + 1)
            {
                f2 = 1;
            }
            k = 0;
        }
        else
        {
            k++;
            if (k >= a)
            {
                f1 = 1;
            }
            g = 0;
        }
    }
    if (f1 || f2)
    {
        cout << n << '\n';
    }
    else
    {
        cout << sum << '\n';
    }
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