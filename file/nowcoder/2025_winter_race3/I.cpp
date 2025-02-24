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
    ll s = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 1)
        {
            s++;
        }
    }
    ll k = 2;
    ll p = a[1];
    ll t = 100;
    ans = 0;
    if (s > n / 2)
    {
        p = 1;
        ans = s;
    }
    else
    {
        p = 0;
        ans = n - s;
    }
    if (n == 1)
    {
        cout << a[1] << ' ' << 2 << '\n';
        return;
    }
    srand(time(NULL));
    while (t--)
    {

        ll a1 = (rand() % n) + 1;
        ll a2 = a1;
        while (a2 == a1)
        {

            a2 = (rand() % n) + 1;
        }
        ll temp = abs(a[a2] - a[a1]);
        // cout << a1 << ' ' << a2 << '\n';
        if (temp == 1)
        {
            continue;
        }
        for (int d = 2; d * d <= temp; ++d)
        {
            if (temp % d == 0)
            {
                while (temp % d == 0)
                {
                    temp /= d;
                }

                int cnt = 0;
                for (int i = 1; i <= n; i++)
                {
                    if ((a[a1] - a[i]) % d == 0)
                    {
                        ++cnt;
                    }
                }
                if (cnt > ans)
                {
                    ans = cnt;
                    p = a[a1] % d;
                    k = d;
                }
            }
        }

        if (temp != 1)
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if ((a[a1] - a[i]) % temp == 0)
                {
                    ++cnt;
                }
            }
            if (cnt > ans)
            {
                ans = cnt;
                p = a[a1] % temp;
                k = temp;
            }
        }
    }
    cout << p << ' ' << k << '\n';
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
