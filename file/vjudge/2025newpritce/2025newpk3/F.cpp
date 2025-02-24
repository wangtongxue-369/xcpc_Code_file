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
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
ll prime[MAXN];
bool f[1000000 + 10];
ll cnt = 0;
void Prime(ll s)
{
    for (int i = 2; i <= s; i++)
    {
        if (!f[i])
        {
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= s; j++)
        {
            f[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}
void solve()
{
    string s;
    cin >> s;
    ll sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += s[i] - '0';
    }
    if (sum % 3 == 0)
    {
        cout << s << '\n';
        return;
    }
    if ((s[4] - '0') % 2 == 0)
    {
        cout << s << '\n';
        return;
    }
    for (int i = 4; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 == 0)
        {
            swap(s[i], s[4]);
            cout << s << '\n';
            return;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (s[i] == '5')
        {
            swap(s[i], s[4]);
            cout << s << '\n';
            return;
        }
    }
    vector<bool> vis(100, 0);
    for (int i1 = 0; i1 < 5; i1++)
    {
        vis[i1] = 1;
        for (int i2 = 0; i2 < 5; i2++)
        {
            if (vis[i2] == 1)
                continue;
            vis[i2] = 1;
            for (int i3 = 0; i3 < 5; i3++)
            {
                if (vis[i3] == 1)
                    continue;
                vis[i3] = 1;
                for (int i4 = 0; i4 < 5; i4++)
                {
                    if (vis[i4] == 1)
                        continue;
                    vis[i4] = 1;
                    for (int i5 = 0; i5 < 5; i5++)
                    {
                        if (vis[i5] == 1)
                            continue;
                        vis[i5] = 1;
                        ll s1 = (s[i1] - '0') * 10000 + (s[i2] - '0') * 1000 + (s[i3] - '0') * 100 + (s[i4] - '0') * 10 + (s[i5] - '0');
                        if (1e4 <= s1 && s1 < 1e5 && f[s1] == 1)
                        {
                            cout << s1 << '\n';
                            return;
                        }
                        vis[i5] = 0;
                    }
                    vis[i4] = 0;
                }
                vis[i3] = 0;
            }
            vis[i2] = 0;
        }
        vis[i1] = 0;
    }
    cout << -1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Prime(1e5);
    // cout << f[11113] << '\n';
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
