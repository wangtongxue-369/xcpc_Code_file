#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 200005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], x[MAXN], prex[MAXN], prea[MAXN];
// 第i位后面最近的>=x的位置
//  最远的>x的位置
void solve()
{
    ll q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[n - i + 1];
    }
    array<ll, 35> last[n + 10];
    for (int w = 0; w <= 32; w++)
    {
        last[n + 1][w] = n;
    }
    for (int i = n; i >= 1; i--)
    {
        // memset(last[i].begin(), 0, sizeof(last[i]));
        x[i] = __lg(a[i]);
        last[i] = last[i + 1];
        last[i][x[i]] = i;
        for (int j = 31; j >= 0; j--)
        {
            last[i][j] = min(last[i][j], last[i][j + 1]);
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= 5; j++)
    //     {
    //         cout << last[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 1; i <= n; i++)
    {
        prea[i] = prea[i - 1] ^ a[i];
    }
    ll s;
    while (q--)
    {
        cin >> s;
        if (s < a[1])
        {
            cout << 0 << ' ';
            continue;
        }
        ans = 0;
        bool flag = 1;
        ll i, p, to, now;
        i = 1;
        while (i <= n && s > 0)
        {
            p = __lg(s);
            to = last[i][p];
            // cout << "! " << s << '\n';
            s ^= prea[to - 1] ^ prea[i - 1];
            // cout << i << ' ' << to << '\n';
            // cout << s << '\n';
            i = to;
            if (s < a[to] || s <= 0)
            {
                break;
            }
            s ^= a[to];
            i++;
        }
        cout << i - 1 << ' ';
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
