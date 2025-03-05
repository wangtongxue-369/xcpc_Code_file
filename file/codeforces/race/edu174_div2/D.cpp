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
string s;
bool check(ll x)
{
    map<ll, ll> ma;
    for (int i = 0; i < x; i++)
    {
        ma[s[i]]++;
    }
    for (int i = 0; i < min(n / 2, n - x); i++)
    {
        if (i < x)
        {
            if (ma[s[n - i - 1]] > 0)
            {
                ma[s[n - i - 1]]--;
                continue;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (s[i] == s[n - i - 1])
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
    }
    for (auto it : ma)
    {
        if (it.second % 2)
        {
            return 0;
        }
    }
    return 1;
}
void solve()
{
    cin >> s;
    n = s.length();
    ll i = 0;
    for (i = 0; i < (n / 2); i++)
    {
        if (s[i] == s[n - i - 1])
        {

            continue;
        }
        else
        {

            break;
        }
    }
    n = s.length() - 2 * (i);
    s = s.substr(i, n);
    ll l = 0, r = s.length();
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    ans = l;
    reverse(s.begin(), s.end());
    l = 0, r = s.length();
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << min(ans, l) << '\n';
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
