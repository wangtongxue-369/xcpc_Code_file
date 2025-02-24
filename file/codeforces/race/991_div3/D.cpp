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
    string s;
    cin >> s;
    n = s.length();
    for (int i = 0; i < s.length(); i++)
    {
        a[i] = s[i] - '0';
    }
    // for (int i = 1; i < n; i++)
    // {
    //     if (a[i] == 0)
    //     {
    //         continue;
    //     }
    //     // cout << i << ' ' << a[i] << '\n';
    //     if (a[i] - 1 > a[i - 1])
    //     {
    //         a[i] -= 1;
    //         swap(a[i], a[i - 1]);
    //         ll j = i - 1;
    //         while (j >= 1 && a[i] - 1 >= a[i - 1])
    //         {
    //             a[i] -= 1;
    //             swap(a[i], a[i - 1]);
    //             j--;
    //         }
    //     }
    // }
    for (int i = 1; i < n; i++)
    {
        while (i >= 1 && a[i] > 0 && a[i - 1] < a[i] - 1)
        {
            a[i] -= 1;
            swap(a[i], a[i - 1]);
            if (i >= 2)
            {
                i--;
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << '\n';
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
