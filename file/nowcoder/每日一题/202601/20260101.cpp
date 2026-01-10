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
using namespace std;

const int N = 100000 + 5;

int n;
vector<int> g[N];
int lch[N], rch[N];
bool is_child[N];

vector<int> pre, in, post;

void dfs(int u)
{
    if (!u)
        return;
    pre.push_back(u);
    dfs(lch[u]);
    in.push_back(u);
    dfs(rch[u]);
    post.push_back(u);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        lch[i] = rch[i] = 0;
        is_child[i] = false;
    }

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        is_child[b] = true;
    }

    // 确定左右孩子
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 2)
        {
            int x = g[i][0], y = g[i][1];
            if (x < y)
            {
                lch[i] = x;
                rch[i] = y;
            }
            else
            {
                lch[i] = y;
                rch[i] = x;
            }
        }
        else if (g[i].size() == 1)
        {
            int x = g[i][0];
            if (x > i)
                lch[i] = x;
            else
                rch[i] = x;
        }
    }

    // 找根
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!is_child[i])
        {
            root = i;
            break;
        }
    }

    dfs(root);

    for (int i = 0; i < pre.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << pre[i];
    }
    cout << '\n';

    for (int i = 0; i < in.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << in[i];
    }
    cout << '\n';

    for (int i = 0; i < post.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << post[i];
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
