#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define reps(i, j, k, step) for (int i = (j); i <= (k); i += (step))
#define per(i, j, k) for (int i = (j); i >= (k); --i)
#define pers(i, j, k, step) for (int i = (j); i >= (k); i -= (step))
#define in_(set) for (auto it : set)
#define mem(a, b) memset(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
#define lson (p << 1)
#define rson (p << 1 | 1)
#define int long long
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define yes "YES"
#define no "NO"
const int mod = 998244353, N = 2e5 + 5, inf = 0x3f3f3f3f3f3f3f3f;
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
        f = c == '-' ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}
inline void write(int x)
{
    if (x < 0)
        x = -x, putchar('-');
    if (x > 9)
        write(x / 10);
    putchar('0' + x % 10);
}

void solve()
{
    int n = read();
    vector<int> a(n + 1);
    vector<pii> ans;
    priority_queue<int, vector<int>, greater<int>> q0, q1, q2;
    rep(i, 1, n)
    {
        a[i] = read();
        if (a[i] == 0)
            q0.push(i);
        else if (a[i] == 1)
            q1.push(i);
        else
            q2.push(i);
    }
    int u = n, v = 0, cnt0 = q0.size(), cnt1 = q1.size(), cnt2 = q2.size();
    while (u + cnt2 > n)
    {
        if (a[u] == 0)
        {
            v = q1.top();
            q1.pop();
            q1.push(u);
            q0.push(v);
            swap(a[u], a[v]);
            ans.pb({u, v});
        }
        if (a[u] == 1)
        {
            v = q2.top();
            q2.pop();
            q2.push(u);
            q1.push(v);
            swap(a[u], a[v]);
            ans.pb({u, v});
        }
        u--;
    }
    while (u + cnt1 + cnt2 > n)
    {
        if (a[u] == 0)
        {
            v = q1.top();
            q1.pop();
            q1.push(u);
            q0.push(v);
            swap(a[u], a[v]);
            ans.pb({u, v});
        }
        u--;
    }
    write(ans.size()), enter;
    for (auto it : ans)
    {
        write(it.fi), space, write(it.se), enter;
    }
}
// * 0 1 2 2 0 0 0 0 2 2
// * q0: 5 6 7 8 9 10
// * q1: 1 10
// * q2: 2 3 4 10

signed main()
{
    int t = 1;
    t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}