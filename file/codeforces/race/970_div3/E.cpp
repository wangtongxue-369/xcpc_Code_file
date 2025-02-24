#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    if (n == 2)
    {
        cout << 0 << '\n';
        return;
    }
    if (n % 2 == 1) // 基数要删
    {
        map<char, ll> hmaj, hmao;
        map<char, ll> qmaj, qmao;
        for (int i = 0; i < n; i += 2)
        {
            hmao[s[i]]++;
        }
        for (int i = 1; i < n; i += 2)
        {
            hmaj[s[i]]++;
        }
        ans = 1e9;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                hmao[s[i]]--;
            }
            else
            {
                hmaj[s[i]]--;
            }
            ll minj = 1e9, mino = 1e9;
            for (auto it : hmaj)
            {
                mino = min(mino, (n - 1) / 2 - it.second - qmao[it.first]);
            }
            for (auto it : hmao)
            {
                minj = min(minj, (n - 1) / 2 - it.second - qmaj[it.first]);
            }
            for (auto it : qmaj)
            {
                minj = min(minj, (n - 1) / 2 - it.second - hmao[it.first]);
            }
            for (auto it : qmao)
            {
                mino = min(mino, (n - 1) / 2 - it.second - hmaj[it.first]);
            }
            ans = min(ans, minj + mino);
            if (i % 2 == 0)
            {
                qmao[s[i]]++;
            }
            else
            {
                qmaj[s[i]]++;
            }
        }
        cout << ans + 1 << '\n';
    }
    else
    {
        vector<ll> f(n + 100, 0);
        map<char, ll> maj, mao;
        for (int i = 0; i < n - 1; i += 2)
        {
            maj[s[i]]++;
        }
        for (int i = 1; i < n; i += 2)
        {
            mao[s[i]]++;
        }
        ll minj = 1e9, mino = 1e9;
        for (auto it : maj)
        {
            minj = min(minj, n / 2 - it.second);
        }
        for (auto it : mao)
        {
            mino = min(mino, n / 2 - it.second);
        }
        cout << minj + mino << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
