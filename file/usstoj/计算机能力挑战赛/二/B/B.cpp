#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0; // a[500005], f[500005];
struct node
{
    string name;
    ll c, pc;
    bool gb, xb;
    ll lw;
    ll sum = 0;
} a[110];
bool cmp(node s1, node s2)
{
    return s1.sum > s2.sum;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char s;
        cin >> a[i].name >> a[i].c >> a[i].pc;
        cin >> s;
        if (s == 'Y')
        {
            a[i].gb = 1;
        }
        else
        {
            a[i].gb = 0;
        }
        cin >> s;
        if (s == 'Y')
        {
            a[i].xb = 1;
        }
        else
        {
            a[i].xb = 0;
        }
        cin >> a[i].lw;
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].c > 80 && a[i].lw >= 1)
        {
            a[i].sum += 8000;
        }
        if (a[i].c > 85 && a[i].pc > 80)
        {
            a[i].sum += 4000;
        }
        if (a[i].c > 90)
        {
            a[i].sum += 2000;
        }
        if (a[i].c > 85 && a[i].xb == 1)
        {
            a[i].sum += 1000;
        }
        if (a[i].pc > 80 && a[i].gb == 1)
        {
            a[i].sum += 850;
        }
        sum += a[i].sum;
        // cout << a[i].sum << '\n';
    }
    stable_sort(a + 1, a + 1 + n, cmp);
    cout << a[1].name << '\n';
    cout << a[1].sum << '\n';
    cout << sum << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
