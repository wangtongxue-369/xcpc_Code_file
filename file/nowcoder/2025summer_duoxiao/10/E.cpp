/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
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
ll maxn = 0, minn = 1e9;
void m1()
{
    ll pi = 0;
    ll sum = 0;
    pi = maxn - a[1];
    sum += pi;
    for (int i = 2; i <= n; i++)
    {
        ll np = maxn - a[i];
        if (np > pi)
        {
            sum += np - pi;
        }
        pi = np;
    }
    ans = min(ans, sum);
}
void m2()
{
    // dp[i][j] 到达i位加到j时的操作数
    // s1-a[i] 当前的操作数
    // s1-a[i-1] 之前的操作数
    for (int s1 = minn; s1 <= maxn + 100; s1++)
    {
        for (int s2 = s1; s2 <= maxn + 100; s2++)
        {
            ll p1 = INF, p2 = INF;
            if (s1 >= a[1])
            {
                p1 = s1 - a[1];
            }
            if (s2 >= a[1])
            {
                p2 = s2 - a[1];
            }
            if (p1 == INF && p2 == INF)
            {
                continue;
            }
            for (int i = 2; i <= n; i++)
            {
                ll np1 = INF, np2 = INF;
                if (s1 >= a[i])
                {
                    if (p1 != INF)
                    {
                        if (s1 - a[i] >= s1 - a[i - 1])
                            np1 = min(np1, p1 + (s1 - a[i]) - (s1 - a[i - 1]));
                        else
                            np1 = min(np1, p1);
                    }
                    if (p2 != INF)
                    {
                        if (s1 - a[i] >= s2 - a[i - 1])
                            np1 = min(np1, p2 + (s1 - a[i]) - (s2 - a[i - 1]));
                        else
                            np1 = min(np1, p2);
                    }
                }
                if (s2 >= a[i])
                {
                    if (p1 != INF)
                    {
                        if (s2 - a[i] >= s1 - a[i - 1])
                            np2 = min(np2, p1 + (s2 - a[i]) - (s1 - a[i - 1]));
                        else
                            np2 = min(np2, p1);
                    }
                    if (p2 != INF)
                    {
                        if (s2 - a[i] >= s2 - a[i - 1])
                            np2 = min(np2, p2 + (s2 - a[i]) - (s2 - a[i - 1]));
                        else
                            np2 = min(np2, p2);
                    }
                }
                p1 = np1, p2 = np2;
                if (p1 > ans && p2 > ans && i != n)
                {
                    break;
                }
                if (p1 == INF && p2 == INF)
                {
                    break;
                }
            }
            if (p1 != INF)
            {
                ans = min(ans, p1);
            }
            if (p2 != INF)
            {
                ans = min(ans, p2);
            }
        }
    }
}
void solve()
{
    ans = INF;
    maxn = 0;
    minn = 1e9;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    if (m == 1)
    {
        m1();
        cout << ans << '\n';
    }
    else
    {
        m1();
        m2();
        cout << ans << '\n';
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