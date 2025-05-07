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

struct node
{
    ll dis, x, y;
    bool operator<(const node &others) const
    {
        if (dis == others.dis)
        {
            if (x == others.x)
            {
                return y < others.y;
            }
            return x < others.x;
        }
        return dis < others.dis;
    }
};
vector<node> p1, p0;
// set<node> t1, t0;
void solve()
{
    set<node> se;
    cin >> n;
    ll op = 0;
    ll t0 = 0, t1 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == 0)
        {
            while (se.contains(p0[t0]))
            {
                t0++;
            }
            // cerr << "!";
            cout << p0[t0].x << ' ' << p0[t0].y << '\n';
            se.insert(p0[t0]);
            // t0++;
        }
        if (op == 1)
        {
            while (se.contains(p1[t1]))
            {
                t1++;
            }
            cout << p1[t1].x << ' ' << p1[t1].y << '\n';
            se.insert(p1[t1]);
            // t1++;
        }
    }
}
//
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i * 3 <= 1000; i++)
    {
        for (int j = 0; j * 3 <= 1000; j++)
        {
            p0.push_back({3 * i + 1 + 3 * j + 1, 3 * i + 1, 3 * j + 1});
            p1.push_back({3 * i + 1 + 3 * j + 1, 3 * i + 1, 3 * j + 1});
            p1.push_back({3 * i + 1 + 3 * j + 2, 3 * i + 1, 3 * j + 2});
            p1.push_back({3 * i + 2 + 3 * j + 1, 3 * i + 2, 3 * j + 1});
            p1.push_back({3 * i + 2 + 3 * j + 2 + 2, 3 * i + 2, 3 * j + 2});
        }
    }
    sort(p0.begin(), p0.end());
    sort(p1.begin(), p1.end());
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}