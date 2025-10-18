/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
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
class Fenw
{
private:
    int n;
    std::vector<int> tree;

    int lowbit(int x)
    {
        return x & -x;
    }

public:
    Fenw() = default;
    Fenw(int size) : n(size), tree(size + 1, 0) {}

    void update(int index, int delta)
    {
        // 转换为1-indexed
        int i = index + 1;
        while (i <= n)
        {
            tree[i] += delta;
            tree[i] %= mod;
            i += lowbit(i);
        }
    }

    int query(int index)
    {
        // 转换为1-indexed
        int i = index + 1;
        int sum = 0;
        while (i > 0)
        {
            sum += tree[i];
            sum %= mod;
            i -= lowbit(i);
        }
        return sum;
    }
};
void solve()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<Fenw> h(n + 10), l(n + 10);
    for (int i = 0; i <= n + 3; i++)
    {
        h[i] = Fenw(n + 10);
        l[i] = Fenw(n + 10);
    }

    h[0].update(0, 1);
    l[0].update(0, 1);

    for (int k = 1; k <= n; k++)
    {
        ll x = a[k];
        vector<array<ll, 3>> ve;

        for (int j = x + 1; j <= n; j++)
        {
            ll sum = h[j].query(x);
            ve.push_back({sum, j, x});
        }

        for (int q = 0; q <= x; q++)
        {
            ll sum = l[q].query(x);
            ve.push_back({sum, x, q});
        }

        for (auto [s1, s2, s3] : ve)
        {
            h[s2].update(s3, s1);
            l[s3].update(s2, s1);
        }
    }

    ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += h[i].query(n);
        ans %= mod;
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