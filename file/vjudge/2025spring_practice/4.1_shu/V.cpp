#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 100005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
vector<vector<ll>> ve;
ll ask(ll x, ll y)
{
    cout << "? " << x << ' ' << y << endl;
    ll res;
    cin >> res;
    return res;
}
void cans(ll x)
{
    cout << "! " << x << endl;
}
vector<ll> s(MAXN + 10); // 这个节点大小（所有子树上节点数+该节点）
vector<ll> w(MAXN + 10); // 每个点的重量（子树大小最大值）

void fun(ll x1, ll fa1, ll sn)
{
    function<int(int, int)> get_size = [&](int u, int fa)
    {
        int res = 1;
        for (auto v : ve[u])
        {
            if (v == fa)
                continue;
            res += get_size(v, u);
        }
        return res;
    };
    // cout << "dangqian " << x1 << endl;
    //  vector<ll> c(10);     // 重心
    ll c = 0, minn = 1e18;
    function<void(ll x, ll fa)> dfs = [&](ll x, ll fa)
    {
        s[x] = 1;
        w[x] = 0;
        for (auto it : ve[x])
        {
            if (it == fa)
            {
                continue;
            }
            dfs(it, x);
            s[x] += s[it];
            w[x] = max(w[x], s[it]);
        }
        w[x] = max(w[x], sn - s[x]);
        if (w[x] < minn)
        {
            c = x;
            minn = w[x];
        }
    };
    dfs(x1, fa1);
    // cout << "zhongxin " << c << endl;
    ll x = c;
    if (ve[x].size() == 0)
    {
        cans(x);
        return;
    }
    else if (ve[x].size() == 1)
    {
        ll t = ask(x, ve[x][0]);
        if (t == 0)
        {
            cans(x);
            return;
        }
        else
        {
            cans(ve[x][0]);
            return;
        }
    }
    else if (ve[x].size() == 2)
    {
        ll t = ask(ve[x][0], ve[x][1]);
        ll s1 = ve[x][0], s2 = ve[x][1];
        if (t == 1)
        {
            cans(x);
            return;
        }
        else if (t == 0)
        {
            // ve[x][0]
            ve[s1].erase(find(ve[s1].begin(), ve[s1].end(), x));
            fun(ve[x][0], x, get_size(s1, x));
            return;
        }
        else if (t == 2)
        {
            ve[s2].erase(find(ve[s2].begin(), ve[s2].end(), x));
            fun(s2, x, get_size(s2, x));
            return;
        }
    }
    else if (ve[x].size() == 3)
    {
        vector<PII> v;
        for (auto it : ve[x])
        {
            v.push_back({s[it], it});
        }
        sort(v.rbegin(), v.rend());
        ll s1 = v[0].second, s2 = v[1].second;
        ll t = ask(s1, s2);
        if (t == 1)
        {
            ve[x].erase(find(ve[x].begin(), ve[x].end(), s1));
            ve[x].erase(find(ve[x].begin(), ve[x].end(), s2));
            fun(x, s1, get_size(x, s1));
            return;
        }
        else if (t == 0)
        {
            ve[s1].erase(find(ve[s1].begin(), ve[s1].end(), x));
            fun(s1, x, get_size(s1, x));
            return;
        }
        else if (t == 2)
        {
            ve[s2].erase(find(ve[s2].begin(), ve[s2].end(), x));
            fun(s2, x, get_size(s2, x));
            return;
        }
    }
}
void solve()
{
    ll l, r;
    cin >> n;
    ve.clear();
    ve.resize(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        if (l != 0)
        {
            ve[i].push_back(l);
            ve[l].push_back(i);
        }
        if (r != 0)
        {
            ve[i].push_back(r);
            ve[r].push_back(i);
        }
    }
    fun(1, 0, n);
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}