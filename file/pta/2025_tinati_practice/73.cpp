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
void solve()
{
    string head, tail;
    map<string, pair<string, string>> l;
    map<string, string> lst;
    set<string> vis;
    cin >> head >> n;
    for (int i = 0; i < n; i++)
    {
        string now, data, nxt;
        cin >> now >> data >> nxt;
        l[now] = {data, nxt};
        if (nxt == "-1")
        {
            tail = now;
        }
        else
        {
            vis.insert(nxt);
            lst[nxt] = now;
        }
    }
    string x = head, y = tail;
    while (1)
    {
        cout << y << ' ' << l[y].first << ' ' << x << endl;
        y = lst[y];
        if (x == y)
        {
            break;
        }

        cout << x << ' ' << l[x].first << ' ' << y << endl;
        x = l[x].second;
        if (x == y)
        {
            break;
        }
    }
    cout << x << ' ' << l[x].first << " -1" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}