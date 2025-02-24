#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 600005;
const ll base1 = 131;
const ll base2 = 127;
const ll N = 600005;
int _ = 1, n, m, ans = INF, MAX, f[N], flag[N], ai, pre[N];
std::pair<int, int> t[4 * N], tag[4 * N];
std::vector<int> b;
std::vector<std::pair<int, int>> ve[N];
using i64 = long long;
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r
#define mapa std::make_pair
// const ll N = 600005;
//  i64 seg[N << 2], lazy[N << 2];
void pushdown(int p)
{
    t[p + p] = std::min(t[p + p], tag[p]);
    tag[p + p] = std::min(tag[p + p], tag[p]);
    t[p + p + 1] = std::min(t[p + p + 1], tag[p]);
    tag[p + p + 1] = std::min(tag[p + p + 1], tag[p]);
    tag[p] = mapa(INF, 0);
}
void pushup(int p) { t[p] = std::min(t[p + p], t[p + p + 1]); }
std::pair<int, int> Query(int p, int l, int r, int x, int y)
{
    if (l == x && r == y)
        return t[p];
    pushdown(p);
    int mid = l + (r - l) / 2;
    if (y <= mid)
        return Query(p + p, l, mid, x, y);
    else if (x > mid)
        return Query(p + p + 1, mid + 1, r, x, y);
    else
        return std::min(Query(p + p, l, mid, x, mid), Query(p + p + 1, mid + 1, r, mid + 1, y));
}
void Update(int p, int l, int r, int x, int y, std::pair<int, int> z)
{
    if (l == x && r == y)
    {
        t[p] = std::min(t[p], z), tag[p] = std::min(tag[p], z);
        return;
    }
    pushdown(p);
    int mid = l + (r - l) / 2;
    if (y <= mid)
        Update(p + p, l, mid, x, y, z);
    else if (x > mid)
        Update(p + p + 1, mid + 1, r, x, y, z);
    else
        Update(p + p, l, mid, x, mid, z), Update(p + p + 1, mid + 1, r, mid + 1, y, z);
    pushup(p);
}
void build(int p, int l, int r)
{
    if (l == r)
    {
        t[p] = mapa(-1, 0), tag[p] = mapa(INF, 0);
        return;
    }
    int mid = l + (r - l) / 2;
    build(p + p, l, mid), build(p + p + 1, mid + 1, r);
    pushup(p);
}
// 2 6 2 7 3 7 5 3
// 2 6 2 10 6 10 5 3
void solve()
{
    // ans=1e18;
    //  cout << "!1" << endl;
    cin >> n >> m;
    ll x, l, r;
    vector<ll> b;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> l >> r;
        ve[x].push_back({l, r});
        b.push_back(l);
        b.push_back(r);
    }
    sort(b.begin(), b.end());
    ll mx = b.size() + 1;
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 1; i <= n; i++)
    {
        // cout << "!2" << endl;
        for (int j = 0; j < ve[i].size(); j++)
        {
            ve[i][j].first = lower_bound(b.begin(), b.end(), ve[i][j].first) - b.begin() + 1;
            ve[i][j].second = lower_bound(b.begin(), b.end(), ve[i][j].second) - b.begin() + 1;
        }
    }
    build(1, 1, mx);
    ll ai = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << "!3" << endl;
        ll minn = INF, pr = 0;
        for (int j = 0; j < ve[i].size(); j++)
        {
            // cout << "!4\n";
            auto now = Query(1, 1, mx, ve[i][j].first, ve[i][j].second);
            if (now.first < minn)
            {
                minn = now.first;
                pr = now.second;
            }
        }
        int fi = minn + i;
        // cout << fi << '\n';
        f[i] = fi;
        pre[i] = pr;
        if (fi + n - i < ans)
        {
            ans = fi + n - i;
            ai = i;
        }
        for (int j = 0; j < ve[i].size(); j++)
        {
            // cout << "!5" << endl;
            Update(1, 1, mx, ve[i][j].first, ve[i][j].second, mapa(fi - i - 1, i));
        }
    }
    while (ai)
    {
        flag[ai] = 1;
        ai = pre[ai];
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
    {
        if (!flag[i])
        {
            cout << i << ' ';
        }
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
//
