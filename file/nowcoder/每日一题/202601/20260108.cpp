
/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#include <bits/stdc++.h>
const int64_t MOD = 1e9 + 7;
const int64_t MAXN = 5e5 + 5;
class SegmentTree
{
private:
    struct Node
    {
        long long sum; // 区间和
        long long mul; // 乘法懒标记
        long long add; // 加法懒标记
    };

    int n;
    std::vector<Node> tr;

    // 建树
    void build(int idx, int l, int r, const std::vector<long long> &a)
    {
        tr[idx].mul = 1;
        tr[idx].add = 0;
        if (l == r)
        {
            tr[idx].sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(idx << 1, l, mid, a);
        build(idx << 1 | 1, mid + 1, r, a);
        pushUp(idx);
    }

    // 向上更新
    void pushUp(int idx)
    {
        tr[idx].sum = tr[idx << 1].sum + tr[idx << 1 | 1].sum;
    }

    // 懒标记下推
    void pushDown(int idx, int l, int r)
    {
        if (tr[idx].mul == 1 && tr[idx].add == 0)
            return;

        int mid = (l + r) >> 1;
        apply(idx << 1, l, mid, tr[idx].mul, tr[idx].add);
        apply(idx << 1 | 1, mid + 1, r, tr[idx].mul, tr[idx].add);

        tr[idx].mul = 1;
        tr[idx].add = 0;
    }

    // 对某个节点整体应用乘+加
    void apply(int idx, int l, int r, long long mul, long long add)
    {
        tr[idx].sum = tr[idx].sum * mul + (r - l + 1) * add;
        tr[idx].mul *= mul;
        tr[idx].add = tr[idx].add * mul + add;
    }

    // 区间乘
    void rangeMul(int idx, int l, int r, int ql, int qr, long long val)
    {
        if (ql <= l && r <= qr)
        {
            apply(idx, l, r, val, 0);
            return;
        }
        pushDown(idx, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            rangeMul(idx << 1, l, mid, ql, qr, val);
        if (qr > mid)
            rangeMul(idx << 1 | 1, mid + 1, r, ql, qr, val);
        pushUp(idx);
    }

    // 区间加
    void rangeAdd(int idx, int l, int r, int ql, int qr, long long val)
    {
        if (ql <= l && r <= qr)
        {
            apply(idx, l, r, 1, val);
            return;
        }
        pushDown(idx, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            rangeAdd(idx << 1, l, mid, ql, qr, val);
        if (qr > mid)
            rangeAdd(idx << 1 | 1, mid + 1, r, ql, qr, val);
        pushUp(idx);
    }

    // 区间求和
    long long querySum(int idx, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return tr[idx].sum;
        }
        pushDown(idx, l, r);
        int mid = (l + r) >> 1;
        long long res = 0;
        if (ql <= mid)
            res += querySum(idx << 1, l, mid, ql, qr);
        if (qr > mid)
            res += querySum(idx << 1 | 1, mid + 1, r, ql, qr);
        return res;
    }

public:
    // 构造函数（数组从 1 开始）
    SegmentTree(const std::vector<long long> &a)
    {
        n = (int)a.size() - 1;
        tr.resize(n * 4 + 4);
        build(1, 1, n, a);
    }

    // 对外接口
    void rangeAdd(int l, int r, long long val)
    {
        rangeAdd(1, 1, n, l, r, val);
    }

    void rangeMul(int l, int r, long long val)
    {
        rangeMul(1, 1, n, l, r, val);
    }

    long long rangeSum(int l, int r)
    {
        return querySum(1, 1, n, l, r);
    }
};
void solve()
{
    int64_t n, q;

    std::cin >> n >> q;
    std::string s;
    std::cin >> s;

    std::vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '1') // 添加边界检查
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }
    SegmentTree seg(arr);

    // 相当于先减一，再乘以-1
    while (q--)
    {
        int64_t op, l, r;
        std::cin >> op >> l >> r;
        if (op == 1)
        {
            seg.rangeAdd(l, r, -1);
            seg.rangeMul(l, r, -1);
        }
        else if (op == 2)
        {
            std::cout << seg.rangeSum(l, r) << "\n";
        }
    }
}
signed main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_--)
    {

        solve();
    }
    return 0;
}