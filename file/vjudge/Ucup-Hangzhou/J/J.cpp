#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m; // ans = 0;// a[500005], f[500005];
struct node
{
    int sc, i, pos;
    string na;
} a[N];
bool cmp(node s1, node s2)
{
    return s1.sc > s2.sc;
}
bool cmp2(node s1, node s2)
{
    return s1.i < s2.i;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i].i = i;
        cin >> a[i].na >> a[i].sc;
    }
    sort(a + 1, a + 1 + n, cmp);
    string ans;
    ll pos = 0;
    for (int i = 1; i <= n; i++)
    {
        pos++;
        if (a[i].sc == a[i - 1].sc)
        {
            a[i].pos = a[i - 1].pos;
            continue;
        }
        a[i].pos = pos;
    }
    sort(a + 1, a + 1 + n, cmp2);
    for (int i = 1; i <= n; i++)
    {
        // cout << i << ' ' << a[i].pos << '\n';
        ans += a[i].na.substr(0, max((int)a[i].na.length() - a[i].pos, 0));
    }
    if (ans.length())
    {
        ans[0] -= 'a' - 'A';
    }
    cout << "Stage: " << ans << '\n';
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
