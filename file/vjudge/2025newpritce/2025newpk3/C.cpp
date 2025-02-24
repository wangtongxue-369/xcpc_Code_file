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
ll _ = 1, n, m, ans = 0, f[MAXN]; // a[MAXN];// f[MAXN];
struct node
{
    ll op, i;
    char c;
} a[MAXN];
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    cin >> m;
    vector<ll> f(n + 10, 0);

    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].op >> a[i].i >> a[i].c;
    }
    ll d = -1;
    ll end = 0;
    for (int i = 1; i <= m; i++)
    {
        if (a[i].op == 2 || a[i].op == 3)
        {
            end = i;
        }
    }
    for (int i = 1; i <= end; i++)
    {
        if (a[i].op == 1)
        {
            s[a[i].i - 1] = a[i].c;
        }
    }
    if (end != 0)
    {
        if (a[end].op == 2)
        {
            d = 0;
            for (int i = 0; i < n; i++)
            {
                if ('A' <= s[i] && s[i] <= 'Z')
                {
                    s[i] += 32;
                }
            }
        }
        else
        {
            d = 1;
            for (int i = 0; i < n; i++)
            {
                if ('a' <= s[i] && s[i] <= 'z')
                {
                    s[i] -= 32;
                }
            }
        }
    }
    for (int i = end + 1; i <= m; i++)
    {
        if (a[i].op == 1)
        {
            s[a[i].i - 1] = a[i].c;
            f[a[i].i - 1] = 1;
        }
    }
    cout << s << '\n';
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
