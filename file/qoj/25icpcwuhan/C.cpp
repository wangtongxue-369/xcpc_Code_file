/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
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
void solve()
{
    cin >> n >> m;
    bool flag = 0;
    if (n == 1 && m == 3)
    {
        cout << "Yes\n";
        cout << "012\n";
        return;
    }
    else if (n == 3 && m == 1)
    {
        cout << "Yes\n";
        cout << "0\n1\n2\n";
        return;
    }
    else if (n == 1 && m == 6)
    {
        cout << "Yes\n";
        cout << "001122\n";
        return;
    }
    else if (n == 6 && m == 1)
    {
        cout << "Yes\n";
        cout << "0\n0\n1\n1\n2\n2\n";
        return;
    }
    if (n == m && n == 3)
    {
        cout << "Yes\n";
        cout << "100\n012\n221\n";
        return;
    }
    if (n == 2)
    {
        if (m == 3)
        {
            cout << "Yes\n012\n012\n";
        }
        else if (m == 6)
        {
            cout << "Yes\n101022\n010122\n";
        }
        else
        {
            cout << "No\n";
        }
        return;
    }
    else if (m == 2)
    {
        if (n == 3)
        {
            cout << "Yes\n00\n11\n22\n";
        }
        else if (n == 6)
        {
            cout << "Yes\n01\n10\n01\n10\n22\n22\n";
        }
        else
        {
            cout << "No\n";
        }
        return;
    }
    if (n == 1 || m == 1)
    {
        cout << "No\n";
        return;
    }
    if ((n % 3 == 0 || m % 3 == 0) && n != 4 && m != 4)
    {
        bool flag = 0;
        if ((m % 3 == 0 && n % 3 != 0) || (n % 3 == 0 && m % 3 == 0 && m < n))
        {
            swap(n, m);
            flag = 1;
        }
        vector<vector<ll>> a(n + 10, vector<ll>(m + 10));
        a[1][1] = 1, a[1][2] = 0, a[1][3] = 0, a[1][4] = 2, a[1][5] = 2, a[1][6] = 1;
        a[2][1] = 0, a[2][2] = 1, a[2][3] = 2, a[2][4] = 0, a[2][5] = 1, a[2][6] = 2;
        a[3][1] = 2, a[3][2] = 2, a[3][3] = 1, a[3][4] = 1, a[3][5] = 0, a[3][6] = 0;
        ll p = 4;
        while (p <= n)
        {
            ll i2 = p;
            for (int i = p - 1; i2 <= n && i >= 1; i--, i2++)
            {
                for (int j = 1; j <= 6; j++)
                {
                    a[i2][j] = a[i][j];
                }
            }
            p = i2;
        }
        for (int j = 7; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                a[i][j] = a[i][j - 6];
            }
        }
        cout << "Yes\n";
        if (flag)
        {
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << a[j][i];
                }
                cout << '\n';
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << a[i][j];
                }
                cout << '\n';
            }
        }
        return;
    }
    if (n % 4 == 0 || m % 4 == 0)
    {
        bool flag = 0;
        if ((m % 4 == 0 && n % 4 != 0) || (n % 4 == 0 && m % 4 == 0 && m < n))
        {
            swap(n, m);
            flag = 1;
        }
        vector<vector<ll>> a(n + 10, vector<ll>(m + 10));
        a[1][1] = 1, a[1][2] = 0, a[1][3] = 0, a[1][4] = 2, a[1][5] = 2, a[1][6] = 1;
        a[2][1] = 0, a[2][2] = 1, a[2][3] = 2, a[2][4] = 0, a[2][5] = 1, a[2][6] = 2;
        a[3][1] = 0, a[3][2] = 1, a[3][3] = 2, a[3][4] = 0, a[3][5] = 1, a[3][6] = 2;
        a[4][1] = 2, a[4][2] = 2, a[4][3] = 1, a[4][4] = 1, a[4][5] = 0, a[4][6] = 0;
        ll p = 5;
        while (p <= n)
        {
            ll i2 = p;
            for (int i = p - 1; i2 <= n && i >= 1; i--, i2++)
            {
                for (int j = 1; j <= 6; j++)
                {
                    a[i2][j] = a[i][j];
                }
            }
            p = i2;
        }
        for (int j = 7; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                a[i][j] = a[i][j - 6];
            }
        }
        cout << "Yes\n";
        if (flag)
        {
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << a[j][i];
                }
                cout << '\n';
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << a[i][j];
                }
                cout << '\n';
            }
        }
        return;
    }

    cout << "No\n";
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