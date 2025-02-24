#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000050;
const ll base1 = 131;
const ll base2 = 127;
ll x, y;
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN], c[MAXN];
ll work1()
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 0)
        {
            if (a[i] != b[i])
            {
                res++;
            }
        }
        else
        {
            if (a[i] == b[i])
            {
                res++;
            }
        }
    }
    return res * x;
}
bool cmp(ll s1, ll s2)
{
    return s1 > s2;
}

void solve()
{
    cin >> n;
    cin >> x >> y;
    string s1;
    cin >> s1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = s1[i - 1] - '0';
    }
    cin >> s1;
    for (int i = 1; i <= n; i++)
    {
        b[i] = s1[i - 1] - '0';
    }
    cin >> s1;
    for (int i = 1; i <= n; i++)
    {
        c[i] = s1[i - 1] - '0';
    }
    y = min(2 * x, y);
    ll s[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1 && b[i] == 1 && c[i] == 1)
        {
            s[1]++;
        }
        if (a[i] == 0 && b[i] == 0 && c[i] == 1)
        {
            s[2]++;
        }
        if (a[i] == 1 && b[i] == 0 && c[i] == 0)
        {
            s[3]++;
        }
        if (a[i] == 0 && b[i] == 1 && c[i] == 0)
        {
            s[4]++;
        }
    }
    sort(s + 1, s + 1 + 4, cmp);
    ll d = 0, p = 0;
    ll sum = s[1] + s[2] + s[3] + s[4];
    if (s[1] > sum / 2)
    {
        d = s[2] + s[3] + s[4];
        p = s[1] - s[2] - s[3] - s[4];
        cout << d * y + p * x << '\n';
        return;
    }
    else
    {
        d = sum / 2;
        p = sum % 2;
        ans = d * y + p * x;
        cout << ans << '\n';
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
