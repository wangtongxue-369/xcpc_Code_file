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
ll _ = 1, n, m, a[MAXN], f[MAXN];
struct node
{
    int kind, prev, next;
    node(int _kind = -1, int _prev = 0, int _next = 0) : kind(_kind), prev(_prev), next(_next) {} // 结构体初始化函数
} l[MAXN];                                                                                        // 双向链表
int cnt;
void insert_back(int x, int kind)
{
    l[++cnt] = node(kind, x, l[x].next);
    if (l[x].next)
    {
        l[l[x].next].prev = cnt;
    }

    l[x].next = cnt;
}
void del(int x)
{
    int prv = l[x].prev, nxt = l[x].next;
    if (nxt)
    {
        l[nxt].prev = prv;
    }

    l[prv].next = nxt;
}
void solve()
{
    cin >> n;
    int prev;
    vector<int> head(1, 1);
    for (int i = 1; i <= n; i++)
    {
        int kind;
        cin >> kind;
        insert_back(i - 1, kind);
        if (i == 1)
            prev = kind;
        else if (kind != prev)
        {
            head.push_back(i);
            prev = !prev;
        }
    }
    while (!head.empty())
    {
        vector<int> tmp;
        for (int i = 0; i < head.size(); i++)
        {
            int t = head[i];
            cout << t << ' ';
            del(t);
            if (l[t].kind == l[l[t].next].kind && l[t].kind != l[l[t].prev].kind)
                tmp.push_back(l[t].next);
        }
        head = tmp;
        cout << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //  cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
