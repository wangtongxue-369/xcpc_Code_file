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
    ll sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum = sum * 10 + s[i] - '0';
    }
    if (sum % 33 == 0)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == '3' && s[i + 1] == '3')
        {
            sum = 0;
            for (int j = 0; j < s.length(); j++)
            {
                if (j == i || j == i + 1)
                {
                    continue;
                }
                sum = sum * 2 + s[i] - '0';
            }
            if (sum % 33 == 0)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
    return;
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
