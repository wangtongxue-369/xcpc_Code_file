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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
struct node
{
    string s;
    ll year, month, day;
    ll h, m, ss;
} a[MAXN];
void solve()
{
    ll h;
    cin >> n >> h >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].s;
        string s;
        cin >> s;
        a[i].year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + s[3] - '0';
        // scanf("%lld-%lld-%lld", &a[i].year, &a[i].month, &a[i].day);
        a[i].month = (s[5] - '0') * 10 + (s[6] - '0');
        a[i].day = (s[8] - '0') * 10 + s[9] - '0';
        // scanf("%lld:%lld:%lld", &a[i].h, &a[i].m, &a[i].ss);
        cin >> s;
        a[i].h = (s[0] - '0') * 10 + s[1] - '0';
        a[i].m = (s[3] - '0') * 10 + s[4] - '0';
        a[i].ss = (s[6] - '0') * 10 + s[7] - '0';
    }
    set<string> s1, s2, s3;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].year == h && a[i].month == m)
        {
            if (7 <= a[i].h && a[i].h <= 8)
            {
                s1.insert(a[i].s);
                continue;
            }
            if (a[i].h == 9 && a[i].m == 0 && a[i].ss == 0)
            {
                s1.insert(a[i].s);
                continue;
            }
            if (18 <= a[i].h && a[i].h <= 19)
            {
                s1.insert(a[i].s);
                continue;
            }
            if (a[i].h == 20 && a[i].m == 0 && a[i].ss == 0)
            {
                s1.insert(a[i].s);
                continue;
            }
            if (11 <= a[i].h && a[i].h <= 12)
            {
                s2.insert(a[i].s);
                continue;
            }
            if (a[i].h == 13 && a[i].m == 0 && a[i].ss == 0)
            {
                s2.insert(a[i].s);
                continue;
            }
            if (22 <= a[i].h && a[i].h <= 23)
            {
                s3.insert(a[i].s);
                continue;
            }
            if (a[i].h <= 0)
            {
                s3.insert(a[i].s);
                continue;
            }
            if (a[i].h == 1 && a[i].m == 0 && a[i].ss == 0)
            {
                s3.insert(a[i].s);
                continue;
            }
        }
    }
    cout << s1.size() << " " << s2.size() << ' ' << s3.size() << '\n';
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
