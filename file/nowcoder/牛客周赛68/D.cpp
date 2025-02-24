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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll s1 = 0, s3 = 0, s5 = 0, s9 = 0, s11 = 0, s15 = 0, s33 = 0, s45 = 0, s99 = 0, s165 = 0, s495 = 0;
    ll s55 = 0;
    // 1 495
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 1 == 0)
            {
                sum++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 495 == 0)
            {
                s495++;
                if (a[i] % 1 == 0)
                {
                    ans += max(0ll, sum - 1);
                }
                else
                {
                    ans += sum;
                }
            }
        }
    }
    // 3 165
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {

            if (a[i] % 3 == 0)
            {
                sum++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            s165++;
            if (a[i] % 165 == 0)
            {
                if (a[i] % 3 == 0)
                {
                    ans += max(0ll, sum - 1);
                }
                else
                {
                    ans += sum;
                }
            }
        }
    }
    // 5 99
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 5 == 0)
            {
                sum++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            s99++;
            if (a[i] % 99 == 0)
            {
                if (a[i] % 5 == 0)
                {
                    ans += max(0ll, sum - 1);
                }
                else
                {
                    ans += sum;
                }
            }
        }
    }
    // 9 55
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 9 == 0)
            {
                sum++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            s55++;
            if (a[i] % 55 == 0)
            {
                if (a[i] % 9 == 0)
                {
                    ans += max(0ll, sum - 1);
                }
                else
                {
                    ans += sum;
                }
            }
        }
    }
    // 11 45
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {

            if (a[i] % 11 == 0)
            {
                sum++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            s45++;
            if (a[i] % 45 == 0)
            {
                if (a[i] % 11 == 0)
                {
                    ans += max(0ll, sum - 1);
                }
                else
                {
                    ans += sum;
                }
            }
        }
    }
    // 15 33
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {

            if (a[i] % 15 == 0)
            {
                sum++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            s33++;
            if (a[i] % 33 == 0)
            {
                if (a[i] % 15 == 0)
                {
                    ans += max(0ll, sum - 1);
                }
                else
                {
                    ans += sum;
                }
            }
        }
    }
    cout << ans << '\n';
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
