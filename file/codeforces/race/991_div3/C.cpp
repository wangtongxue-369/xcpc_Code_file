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
    map<ll, ll> ma;
    ll sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        ma[s[i] - '0']++;
        sum += s[i] - '0';
    }
    ll s2 = ma[2], s3 = ma[3];
    sum %= 9;
    if (sum == 0)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i <= s2 + s3; i++)
    {
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
        ll ss = 3 * i + 6 * i - sum + 100 - 100;
        if ((9 * i - sum) % 2 == 0)
        {
            ll c2 = ss % 6;
            c2 /= 2;
            if (ss / 6 > s3)
            {
                c2 = c2 + (ss / 6) * 3 - s3 * 3;
            }
            if (c2 <= s2)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
    return;
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
