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
ll _ = 1, n, m, ans = 0, a[MAXN][4], b[MAXN];
void solve()
{
    cin >> n;
    char c;
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        if (c == '?')
        {
            a[i][1] = -1;
            continue;
        }
        a[i][1] = c - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        if (c == '?')
        {
            a[i][2] = -1;
            continue;
        }
        a[i][2] = c - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        if (c == '?')
        {
            a[i][3] = -1;
            continue;
        }
        a[i][3] = c - '0';
    }
    set<ll> se[4];
    for (int w = 1; w <= 3; w++)
    {
        for (int i = w; i <= n; i += 3)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (a[i][j] != -1)
                {
                    se[w - 1].insert(a[i][j]);
                }
            }
        }
    }
    bool flag = 1;
    for (int i = 1; i <= 3; i++)
    {
        if (se[i - 1].size() > 3)
        {
            cout << 0 << '\n';
            return;
        }
    }
    for (int w = 1; w <= n - 2; w++)
    {
        map<ll, ll> ma;
        for (int i = w; i <= w + 2; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (a[i][j] != -1)
                {
                    ma[a[i][j]]++;
                }
            }
        }
        for (auto it : ma)
        {
            if (it.second > 1)
            {
                cout << 0 << '\n';
                return;
            }
        }
    }
    vector<ll> p;
    for (int i = 1; i <= 9; i++)
    {
        p.push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = 0;
        for (int j = 1; j <= 3; j++)
        {
            if (a[i][j] == -1)
            {
                b[i]++;
            }
        }
    }
    ans = 0;
    ll sum = 1;
    for (int i = 4; i <= n; i++)
    {
        if (b[i] == 0 || b[i] == 1)
        {
            sum *= 1;
        }
        else if (b[i] == 2)
        {
            sum *= 2;
        }
        else if (b[i] == 3)
        {
            sum *= 6;
        }
        sum = sum % mod;
    }

    do
    {
        bool flag = 1;

        if (flag)
        {
            ans = (ans + sum) % mod;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
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
