#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int mod = 1000000000 + 7;

struct DSU
{
    vector<int> pa, size;

    DSU(int size_)
    {
        pa.assign(size_, 0), size.assign(size_, 1);
        iota(pa.begin(), pa.end(), 0);
    }
    int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }

    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (size[x] < size[y])
            swap(x, y);
        pa[y] = x;
        size[x] += size[y];
        return true;
    }
};

int qpow(int a, int n = mod - 2)
{
    int res{1};
    for (; n; n >>= 1, a = a * a % mod)
        if (n & 1)
            res = res * a % mod;
    return res;
}

void slove()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cnt(m);
    string s;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        for (int j = 0; j < m; ++j)
        {
            if (s[j] == '1')
                cnt[j].push_back(i);
        }
    }
    DSU dsu(n);
    for (int i = 0; i < m; ++i)
    {
        if ((int)cnt[i].size() + (int)cnt[m - i - 1].size() > 2 || i == m - i - 1 && (int)cnt[i].size() > 1)
        {
            cout << "0\n";
            return;
        }
        for (int j = 1; j < (int)cnt[i].size(); ++j)
        {
            dsu.unite(cnt[i][j], cnt[i][j - 1]);
        }
        for (int j = 1; j < (int)cnt[m - i - 1].size(); ++j)
        {
            dsu.unite(cnt[m - i - 1][j], cnt[m - i - 1][j - 1]);
        }
        if (cnt[i].size() && cnt[m - i - 1].size())
            dsu.unite(cnt[i][0], cnt[m - i - 1][0]);
    }
    // for (int i = 0; i <= m / 2; i ++) {
    // cout << cnt[i].size() << ": ";
    // for (int &x: cnt[i]) cout << x << ' ';
    // cout << '\n';
    // }
    set<int> f;
    for (int i = 0; i < n; ++i)
        f.insert(dsu.pa[i]);
    cout << qpow(2, f.size()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll _{1};
    cin >> _;
    while (_--)
    {
        slove();
    }
    return 0;
}