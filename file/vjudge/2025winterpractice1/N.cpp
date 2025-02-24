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
ll _ = 1, n, m, a[MAXN], b[MAXN], p;
ll res[MAXN], lena, lenb, lenres;
void mo()
{
    vector<ll> ans(1050, 0);
    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            if (i + j - 1 <= 505)
            {
                ans[i + j - 1] += a[i] * res[j];
            }
        }
    }
    for (int i = 1; i <= 500; i++)
    {
        if (ans[i] > 9)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    for (int i = 1; i <= 505; i++)
    {
        res[i] = ans[i];
    }
}
void ma()
{

    vector<ll> ans(1050, 0);
    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            if (i + j - 1 <= 505)
            {
                ans[i + j - 1] += a[i] * a[j];
            }
        }
    }

    for (int i = 1; i <= 500; i++)
    {
        if (ans[i] > 9)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }

    for (int i = 1; i <= 505; i++)
    {
        a[i] = ans[i];
    }
}
void solve()
{
    cin >> p;
    ll len = 1.0 * log10(1.0 * 2) * p + 1;
    cout << len << endl;
    a[1] = 2;
    res[1] = 1;
    while (p)
    {
        if (p & 1)
        {
            mo();
        }
        ma();
        p >>= 1;
    }
    res[1]--;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 50; j++)
        {
            cout << res[500 - ((i - 1) * 50 + j) + 1];
        }
        cout << endl;
    }
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
