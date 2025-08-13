#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1050;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0;
char a[MAXN][MAXN];
int vis[MAXN][MAXN][11];
int tx[] = {-1, 0, 1, 0};
int ty[] = {0, -1, 0, 1};
struct node
{
    PII p;
    ll cnt = 0;
    ll la = 1;
    char c;
};
void solve()
{
    ll k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    queue<node> q;
    q.push({{1, 1}, 0, 1, 'A'});
    ll x, y, cnt, la;
    char c;
    while (!q.empty())
    {
        node no = q.front();
        q.pop();
        x = no.p.first, y = no.p.second, cnt = no.cnt, la = no.la, c = no.c;
        if (x == n && y == m)
        {
            cout << cnt << '\n';
            return;
        }
        if (vis[x][y][la])
        {
            continue;
        }
        vis[x][y][la] = 1;
        for (int i = 0; i < 4; i++)
        {
            ll xx = x + tx[i];
            ll yy = y + ty[i];
            if (1 <= xx && xx <= n && 1 <= yy && yy <= m)
            {
                if (la >= k)
                {
                    if (a[xx][yy] != c)
                    {
                        q.push({{xx, yy}, cnt + 1, 1, a[xx][yy]});
                    }
                }
                else
                {
                    if (a[xx][yy] == c)
                    {
                        q.push({{xx, yy}, cnt + 1, la + 1, c});
                    }
                }
            }
        }
    }
    cout << -1 << '\n';
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