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

// 线段树节点定义
struct SegmentTree
{
    vector<ll> maxTree, minTree;
    int size;

    SegmentTree(int n)
    {
        size = n;
        maxTree.resize(4 * n);
        minTree.resize(4 * n);
        build(1, 1, n);
    }

    void build(int node, int l, int r)
    {
        if (l == r)
        {
            maxTree[node] = a[l];
            minTree[node] = a[l];
        }
        else
        {
            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            maxTree[node] = max(maxTree[2 * node], maxTree[2 * node + 1]);
            minTree[node] = min(minTree[2 * node], minTree[2 * node + 1]);
        }
    }

    ll queryMax(int node, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return -INF;
        if (ql <= l && qr >= r)
            return maxTree[node];
        int mid = (l + r) / 2;
        return max(queryMax(2 * node, l, mid, ql, qr), queryMax(2 * node + 1, mid + 1, r, ql, qr));
    }

    ll queryMin(int node, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return INF;
        if (ql <= l && qr >= r)
            return minTree[node];
        int mid = (l + r) / 2;
        return min(queryMin(2 * node, l, mid, ql, qr), queryMin(2 * node + 1, mid + 1, r, ql, qr));
    }
};

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // SegmentTree st(n);
    bool flag = 0;
    function<void(ll l, ll r)> dfs = [&](ll l, ll r)
    {
        if (l == r)
        {
            return;
        }
        ll maxn = 0, minn = 1e18;
        for (ll i = l; i <= r; i++)
        {
            maxn = max(maxn, a[i]);
            minn = min(minn, a[i]);
        }
        if (maxn - minn + 1 == r - l + 1)
        {
            // cerr << l << ' ' << ((r + l) >> 1) << '\n';
            dfs(l, ((r + l) >> 1));
            // cerr << ((r + l) >> 1) + 1 << ' ' << r << '\n';
            dfs(((r + l) >> 1) + 1, r);
        }
        else
        {
            flag = 1;
            return;
        }
    };
    dfs(1, n);
    if (flag)
    {
        cout << -1 << '\n';
        return;
    }
    ans = 0;
    function<void(ll l, ll r, ll nl, ll nr)> df = [&](ll l, ll r, ll nl, ll nr)
    {
        if (l == r)
        {
            return;
        }
        ll maxl = 0, maxr = 0, minl = 1e18, minr = 1e18;
        for (ll i = l; i <= ((l + r) >> 1); i++)
        {
            maxl = max(maxl, a[i]);
            minl = min(minl, a[i]);
        }
        for (ll i = ((l + r) >> 1) + 1; i <= r; i++)
        {
            maxr = max(maxr, a[i]);
            minr = min(minr, a[i]);
        }
        if (minl < minr)
        {
            df(l, ((l + r) >> 1), minl, maxl);
            df(((l + r) >> 1) + 1, r, minr, maxr);
        }
        else
        {
            ans++;
            ll len = ((l + r) >> 1) - l + 1;
            for (int i = l; i <= ((l + r) >> 1); i++)
            {
                swap(a[i], a[i + len]);
            }
            df(l, ((l + r) >> 1), minr, maxr);
            df(((l + r) >> 1) + 1, r, minl, maxl);
        }
    };
    df(1, n, 1, n);
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}