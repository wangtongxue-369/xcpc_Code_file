#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000055;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
ll prime[MAXN];
bool isp[MAXN];
ll idx = 0;
void initP()
{
    isp[0] = true;
    isp[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!isp[i])
        {
            prime[idx++] = i;
        }

        for (int j = 0; j < idx && i * prime[j] <= MAXN; j++)
        {
            isp[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}
ll check(ll x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void solve()
{
    ans = 0;
    ll e;
    cin >> n >> e;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll p = 0;
    for (int w = 1; w <= e; w++)
    {
        p = 0;
        bool flag = 0;
        ll prep = 0;
        for (int i = w; i <= n; i += e)
        {
            if (a[i] == 1)
            {
                p++;
                continue;
            }
            else if (!isp[a[i]])
            {
                // cout << "! " << a[i] << '\n';
                if (flag == 0)
                {
                    flag = 1;
                    ans += p;
                    prep = p;
                    p = 0;
                }
                else
                {
                    ans += p + p + p * prep;
                    prep = p;
                    p = 0;
                }
                continue;
            }
            else
            {
                if (flag)
                {
                    ans += p + p * prep;
                }
                p = 0;
                flag = 0;
                prep = 0;
            }
        }
        if (flag == 1)
        {
            ans += p + p * prep;
        }
        // cout << ans << '\n';
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    initP();
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
