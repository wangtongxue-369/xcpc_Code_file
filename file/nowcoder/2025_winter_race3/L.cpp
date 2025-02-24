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
vector<int> du(MAXN);
vector<vector<ll>> ve(MAXN);
vector<int> eulerPath;
void findEulerPath(int u)
{
    stack<int> stk;
    stk.push(u);
    while (!stk.empty())
    {
        int v = stk.top();
        if (ve[v].empty())
        {
            eulerPath.push_back(v);
            stk.pop();
        }
        else
        {
            int w = ve[v].back();
            ve[v].pop_back();
            // 删除无向边 (v, w)
            ve[w].erase(find(ve[w].begin(), ve[w].end(), v));
            stk.push(w);
        }
    }
}
void solve()
{
    cin >> n;

    ll p = 1;
    p = 2;
    n++;
    for (int i = 2; i <= n; i++)
    {
        ve[p].push_back(p - i + 1);
        ve[p - i + 1].push_back(p);
        du[p]++, du[p - i + 1]++;

        ve[p].push_back(p + 1);
        ve[p + 1].push_back(p);
        du[p]++, du[p + 1]++;
        for (int j = p + 1; j < p + i - 1; j++)
        {
            ve[j].push_back(j - i);
            ve[j - i].push_back(j);
            du[j]++, du[j - i]++;

            ve[j].push_back(j - i + 1);
            ve[j - i + 1].push_back(j);
            du[j]++, du[j - i + 1]++;

            ve[j].push_back(j + 1);
            ve[j + 1].push_back(j);
            du[j]++, du[j + 1]++;
        }
        p = p + i - 1;
        ve[p].push_back(p - i);
        ve[p - i].push_back(p);
        du[p]++, du[p - i]++;
        p++;
    }
    // for (int i = 1; i <= p - 1; i++)
    // {
    //     for (auto it : ve[i])
    //     {
    //         cout << it << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << "Yes\n";
    findEulerPath(1);
    for (int v : eulerPath)
    {
        cout << v << " ";
    }
    cout << "\n";
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
