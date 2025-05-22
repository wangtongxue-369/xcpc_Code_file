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
    cin >> n;
    string s1, s2, t1, t2;
    cin >> s1 >> s2 >> t1 >> t2;
    ll s11 = 0, s10 = 0, s21 = 0, s20 = 0;
    for (int i = 0; i < n; i++)
    {
        if (t1[i] == '1')
        {
            if (s1[i] == '1')
            {
                s11++;
            }
            else
            {
                s10++;
            }
        }
        if (t2[i] == '1')
        {
            if (s2[i] == '1')
            {
                s21++;
            }
            else
            {
                s20++;
            }
        }
    }
    // cout << s11 << ' ' << s10 << ' ' << s21 << ' ' << s20 << '\n';
    ans = 0;
    ll tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (t1[i] == '0' && t2[i] == '0')
        {
            if (s1[i] == s2[i])
            {
                ans++;
            }
            continue;
        }
        if (t1[i] == '0' && t2[i] == '1')
        {
            if (s1[i] == '1')
            {
                if (s21)
                {
                    ans++, s21--;
                    continue;
                }
                else
                {
                    s20--;
                    continue;
                }
            }
            else
            {
                if (s20)
                {
                    ans++, s20--;
                    continue;
                }
                else
                {
                    s21--;
                    continue;
                }
            }
        }
        if (t1[i] == '1' && t2[i] == '0')
        {
            if (s2[i] == '1')
            {
                if (s11)
                {
                    ans++, s11--;
                    continue;
                }
                else
                {
                    s10--;
                    continue;
                }
            }
            else
            {
                if (s10)
                {
                    ans++, s10--;
                    continue;
                }
                else
                {
                    s11--;
                    continue;
                }
            }
        }
        if (t1[i] == '1' && t2[i] == '1')
        {
            tmp++;
        }
    }
    // cout << s11 << ' ' << s10 << ' ' << s21 << ' ' << s20 << '\n';
    cout << ans + min(tmp, min(s11, s21) + min(s10, s20)) << '\n';
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