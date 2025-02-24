#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll s = count(a + 1, a + 1 + n, -1);
    if (s == n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i % 2 + 1 << ' ';
        }
        cout << '\n';
        return;
    }
    else
    {
        ll i = 1;
        while (a[i] == -1)
        {
            i++;
        }
        // cout << '?' << ' ' << i << '\n';
        for (int j = i - 1; j >= 1; j--)
        {
            if (a[j + 1] == 1)
            {
                a[j] = 2;
            }
            else
            {
                a[j] = a[j + 1] / 2;
            }
        }
        ll j;
        for (; i <= n; i++)
        {
            if (a[i] == -1)
            {
                j = i;
                while (a[j] == -1 && j <= n)
                {
                    j++;
                }
                j--;
                if (j == n)
                {
                    break;
                }
                ll l = i - 1, r = j + 1;
                while (l + 1 < r)
                {
                    if (a[l] > a[r])
                    {
                        a[l + 1] = a[l] == 1 ? 2 : a[l] / 2;
                        l++;
                    }
                    else
                    {
                        a[r - 1] = a[r] == 1 ? 2 : a[r] / 2;
                        r--;
                    }
                }
                if (a[l] != a[r] / 2 && a[l] / 2 != a[r])
                {
                    cout << -1 << '\n';
                    return;
                }
                i = j + 1;
            }
            else
            {
                if (a[i] != a[i - 1] / 2 && a[i] / 2 != a[i - 1] && i != 1)
                {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
        for (; i <= n; i++)
        {
            if (a[i - 1] == 1)
            {
                a[i] = 2;
            }
            else
            {
                a[i] = a[i - 1] / 2;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
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
