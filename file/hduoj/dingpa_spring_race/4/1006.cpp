#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0;
class SegmentTree
{
private:
    vector<int> tree;
    int n;

    void build(const vector<int> &a, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = a[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(a, 2 * node, start, mid);
            build(a, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
        {
            return 0;
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftSum = query(2 * node, start, mid, l, r);
        int rightSum = query(2 * node + 1, mid + 1, end, l, r);
        return leftSum + rightSum;
    }

    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            tree[node] = val;
        }
        else
        {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid)
            {
                update(2 * node, start, mid, idx, val);
            }
            else
            {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

public:
    SegmentTree(const vector<int> &a)
    {
        n = a.size();
        tree.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }

    void update(int idx, int val)
    {
        update(1, 0, n - 1, idx, val);
    }
};
void solve()
{
    ll q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SegmentTree st(a);
    ans = 0;
    ll c, x, y;
    m = 1;
    for (int i = 1; i <= q; i++)
    {
        cin >> c;
        if (c == 1)
        {
            cin >> x >> y;
            st.update(x - 1, y);
        }
        else
        {
            cin >> x >> y;
            // cout << st.query(0, y - 1) - st.query(0, x - 2) << '\n';
            ans = ans ^ (((st.query(0, y - 1) / 100 - st.query(0, x - 2) / 100)) * m);
            // cout << ((st.query(0, y - 1) / 100 - st.query(0, x - 2) / 100)) << '\n';
            m++;
        }
    }
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
