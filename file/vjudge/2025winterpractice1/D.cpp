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
ll _ = 1, n, m; // ans = 0, a[MAXN], f[MAXN];
// islower(x)
// isdigit(x)
void solve()
{
    ll p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;
    string ans;
    ans += s[0];
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i] == '-')
        {
            if (s[i + 1] == '-')
            {
                ans += s[i];
                continue;
            }
            if (s[i - 1] >= s[i + 1] || (isdigit(s[i - 1]) + isdigit(s[i + 1]) == 1) || s[i - 1] == '-')
            {
                // ans += s[i - 1];
                ans += s[i];
                continue;
            }
            if (p1 == 1)
            {
                if (p3 == 1)
                {
                    // ans += s[i - 1];
                    for (int c = s[i - 1] + 1; c <= s[i + 1] - 1; c++)
                    {
                        for (int w = 1; w <= p2; w++)
                            ans += c;
                    }
                }
                else
                {
                    // ans += s[i - 1];
                    for (int c = s[i + 1] - 1; c >= s[i - 1] + 1; c--)
                    {
                        for (int w = 1; w <= p2; w++)
                            ans += c;
                    }
                }
            }
            else if (p1 == 2)
            {
                if (p3 == 1)
                {
                    if (isdigit(s[i - 1]))
                    {
                        // ans += s[i - 1];
                        for (int c = s[i - 1] + 1; c <= s[i + 1] - 1; c++)
                        {
                            for (int w = 1; w <= p2; w++)
                                ans += c;
                        }
                    }
                    else
                    {
                        // ans += s[i - 1];
                        for (int c = s[i - 1] + 1; c <= s[i + 1] - 1; c++)
                        {
                            for (int w = 1; w <= p2; w++)
                                ans += c - 32;
                        }
                    }
                }
                else
                {
                    if (isdigit(s[i - 1]))
                    {
                        // ans += s[i - 1];
                        for (int c = s[i + 1] - 1; c >= s[i - 1] + 1; c--)
                        {
                            for (int w = 1; w <= p2; w++)
                                ans += c;
                        }
                    }
                    else
                    {
                        // ans += s[i - 1];
                        for (int c = s[i + 1] - 1; c >= s[i - 1] + 1; c--)
                        {
                            for (int w = 1; w <= p2; w++)
                                ans += c - 32;
                        }
                    }
                }
            }
            else
            {
                // ans += s[i - 1];
                for (int c = s[i - 1] + 1; c <= s[i + 1] - 1; c++)
                {
                    for (int w = 1; w <= p2; w++)
                        ans += '*';
                }
            }
        }
        else
        {
            ans += s[i];
        }
    }
    cout << ans + s[s.length() - 1] << '\n';
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
