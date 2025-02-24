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
char c[10][10];
ll tx[] = {0, 0, -1, 0, 1, 1, -1, 1, -1};
ll ty[] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
bool check(ll x, ll y)
{
    ll s = 0;
    for (ll i = 1; i <= 8; i++)
    {
        ll x1 = x + tx[i], x2 = x + 2 * tx[i];
        ll y1 = y + ty[i], y2 = y + 2 * ty[i];
        if (1 <= x1 && x1 <= 3 && 1 <= x2 && x2 <= 3)
        {
            if (1 <= y1 && y1 <= 3 && 1 <= y2 && y2 <= 3)
            {
                if ((c[x1][y1] == 'X') && (c[x2][y2] == 'X'))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool check2(ll x, ll y)
{
    for (ll i = 1; i <= 8; i++)
    {
        ll x1 = x + tx[i], x2 = x + 2 * tx[i];
        ll y1 = y + ty[i], y2 = y + 2 * ty[i];
        if (1 <= x1 && x1 <= 3 && 1 <= x2 && x2 <= 3)
        {
            if (1 <= y1 && y1 <= 3 && 1 <= y2 && y2 <= 3)
            {
                if ((c[x1][y1] == 'X' || c[x1][y1] == 'G') && (c[x2][y2] == 'X' || c[x2][y2] == 'G'))
                {
                    return true;
                }
            }
        }
    }

    return false;
}
ll dfs(ll p)
{
    if (p == 3)
    {
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (c[i][j] == 'X' && check(i, j))
                {
                    return 2;
                }
            }
        }
    }
    else
    {
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (c[i][j] == 'G')
                {
                    c[i][j] = 'X';
                    ll x = dfs(p + 1);
                    if (x == 2)
                    {
                        return 2;
                    }
                    c[i][j] = 'G';
                }
            }
        }
    }
    return -1;
}
void solve()
{
    ll sum = 0;
    ll x = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 'X')
            {
                x++;
            }
        }
    }
    if (x <= 2)
    {
        cout << "Yes\n";
        return;
    }
    if (x == 4)
    {
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (c[i][j] == 'G')
                {
                    c[i][j] = 'X';
                }
            }
        }
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (c[i][j] == 'X' && check(i, j))
                {
                    cout << "Yes\n";
                    return;
                }
            }
        }
        cout << "No\n";
        return;
    }
    if (x == 3)
    {
        ll x = dfs(1);
        if (x == -1)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
        return;
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
