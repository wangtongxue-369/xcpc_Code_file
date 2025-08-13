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
    ll t;
    cin >> n >> t;
    string s;
    cin >> s;
    // s=' '+s；
    ll p = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            p = i;
            break;
        }
    }
    // cerr << p << '\n';
    ans = 1e9;
    ll sum = 0;
    // p=2 n=3  5
    for (int i = p; i < p + n;)
    {
        sum++;
        // cerr << i << ' ';
        ll s1 = i, s2 = i + 1;
        while (s[s2 % n] == '0')
        {
            s2++;
        }
        // cerr << s1 << ' ' << s2 << '\n';
        ll len = s2 - s1 - 1;
        // cerr << len << '\n';
        if (len == 0)
        {
        }
        else if (2 * t <= len)
        {
            sum += 2 * t;
        }
        else
        {
            sum += len;
        }
        i = s2;
    }
    ans = sum;
    // cerr << "! " << sum << '\n';
    for (int i = p; i < p + n;)
    {
        ll s1 = i, s2 = i + 1;
        while (s[s2 % n] == '0')
        {
            s2++;
        }
        ll len = s2 - s1 - 1;
        if (len == 0)
        {
        }
        else if (2 * t <= len)
        {
            ans = min(ans, sum - t + 1);
        }
        else
        {
            if (t < len)
            {
                ans = min(ans, sum - (t - (2 * t - len)) + 1);
            }
            else
            {
                ans = min(ans, sum);
            }
            // ll c = min(2 * min(len, t) - len, min(len, t));
            // // cerr << c << '\n';
            // if (c == len)
            // {
            //     ans = min(ans, sum - (min(t, len) - c));
            // }
            // else
            // {
            //     ans = min(ans, sum - (min(t, len) - c) + 1);
            // }
        }
        i = s2;
    }

    cout << n - ans << '\n';
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