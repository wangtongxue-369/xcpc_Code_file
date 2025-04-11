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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
int pre[10010];
int find(int x)
{
    if (pre[x] == x)
        return x;
    return pre[x] = find(pre[x]);
}
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        pre[x] = y;
}
void solve()
{
    int n, x, y, m, a;
    for (int i = 1; i <= 10000; i++)
        pre[i] = i;
    set<int> s, ss;
    cin >> n;
    while (n--)
    {
        cin >> m;
        cin >> x;
        s.insert(x);
        for (int i = 1; i < m; i++)
        {
            cin >> y;
            s.insert(y);
            unite(x, y);
        }
    }
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        ss.insert(find(*it));
    printf("%d %d\n", s.size(), ss.size());
    cin >> a;
    while (a--)
    {
        cin >> x >> y;
        if (find(x) == find(y))
            puts("Y");
        else
            puts("N");
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}