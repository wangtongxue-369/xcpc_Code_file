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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
void solve()
{
    cin >> n >> m;
    ll suma = 0, sumb = 0, sum = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            sum--;
        }
    }
    if (sum < n)
    {
        sum++;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    ll p1 = 1, p2 = 1, ex = 0;
    ll cnt = n;
    for (int p2 = 1; p2 <= m; p2++)
    {
        while (p1 <= n)
        {
            if (a[p1] <= ex + 1)
            {
                ex++;
                p1++;
            }
            else
            {
                break;
            }
        }
        b[p2] -= ex;
        if (b[p2] <= sum)
        {
            sum -= max(0ll, b[p2]);
            ex++;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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