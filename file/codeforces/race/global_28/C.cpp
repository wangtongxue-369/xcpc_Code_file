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
    n = s.length();
    s = ' ' + s;
    ll p = 1;
    while (s[p] == '0')
    {
        p++;
    }
    ll tag = 0;
    ll maxn = 0;
    ll ansl = 1, ansr = 1;
    for (int i = p; i <= n; i++)
    {
        if (s[i] == '0')
        {
            ansl = i, ansr = i;
            tag = i;
            ll len = (n - i + 1);
            for (int j = p; j < i; j++)
            {
                ll tmp = 0;
                if (s[j] == '1')
                {
                    for (int k = 0; k < len; k++)
                    {
                        if ((s[i + k] == '0' && s[j + k] == '1') || (s[i + k] == '1' && s[j + k] == '0'))
                        {
                            tmp++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    continue;
                }
                if (tmp > maxn)
                {
                    ansl = j, ansr = j + len - 1;
                    maxn = tmp;
                }
            }
        }
        if (maxn != 0)
        {
            break;
        }
    }
    cout << ansl << ' ' << ansr << ' ' << p << ' ' << n << '\n';
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
