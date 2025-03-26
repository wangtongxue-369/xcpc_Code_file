#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
using i64 = long long;
struct DSU
{
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    DSU d(n);
    for (int i = 0; i < n; i++)
    {
        if (i - a[i] >= 0)
        {
            d.merge(i, i - a[i]);
        }
        if (i + a[i] < n)
        {
            d.merge(i, i + a[i]);
        }
    }
    ans = 0;
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[d.find(i)] == 0)
        {
            vis[d.find(i)] = 1;
            ans++;
        }
    }
    cout << ans - 1 << '\n';
    // cout << d.size(n) - 1 << '\n';
    //  ans = 0;
    //  for (int i = 1; i <= n; i++)
    //  {
    //      if (f[i] == 1)
    //      {
    //          continue;
    //      }
    //      ans++;
    //      queue<ll> q;
    //      q.push(i);
    //      while (!q.empty())
    //      {
    //          ll p = q.front();
    //          q.pop();
    //          if (f[p] == 1)
    //          {
    //              continue;
    //          }
    //          if (p - a[p] >= 1 && f[p - a[p]] == 0)
    //          {
    //              q.push(p - a[p]);
    //          }
    //          if (p + a[p] <= n && f[p + a[p]] == 0)
    //          {
    //              q.push(p + a[p]);
    //          }
    //          f[p] = 1;
    //      }
    //      for (int i = 1; i <= n; i++)
    //      {
    //          cout << f[i] << ' ';
    //      }
    //      cout << '\n';
    //  }
    //  cout << ans - 1 << '\n';
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
