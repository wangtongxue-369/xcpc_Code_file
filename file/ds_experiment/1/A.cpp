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
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
#define MAXN 1050
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n = 0, m, ans = 0; // a[MAXN], f[MAXN];
using namespace std;
typedef struct node
{
    char c[64];
} node;
char city[1000][64];
int ve[1050][1050];
ll visi[MAXN];
ll citygetid(char c[])
{
    for (int i = 1; i <= n; i++)
    {
        if (strcmp(c, city[i]) == 0)
        {
            return i;
        }
    }
    return 0;
}
node idgetcity(ll i)
{
    node s;
    strcpy(s.c, city[i]);
    return s;
}
void op1()
{
    priority_queue<ll> q;
    scanf("%ld%ld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }
            ve[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", city[i]);
    }
    ll u, v;
    int w;
    char c1[64], c2[64];
    for (int i = 1; i <= m; i++)
    {
        scanf("%s%s%ld", c1, c2, &w);
        u = citygetid(c1);
        v = citygetid(c2);
        // printf("%ld %ld\n", u, v);
        ve[u][v] = w;
        ve[v][u] = w;
    }
}
void op2()
{
    if (n == 0)
    {
        printf("error!\n");
        return;
    }
    printf("请输入起点终点\n");
    char c1[64], c2[64];
    scanf("%s%s", c1, c2);
    ll src = citygetid(c1);
    ll dst = citygetid(c2);
    int dist[MAXN], vis[MAXN], pre[MAXN];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        vis[i] = 0;
        pre[i] = -1;
    }
    dist[src] = 0;

    for (int it = 1; it <= n; ++it)
    {
        int u = -1;
        for (int i = 1; i <= n; i++)
            if (!vis[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        if (u == -1 || dist[u] == INF)
            break;
        vis[u] = 1;
        for (int v = 1; v <= n; ++v)
        {
            if (ve[u][v] < INF && dist[v] > dist[u] + ve[u][v])
            {
                dist[v] = dist[u] + ve[u][v];
                pre[v] = u;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dist[i]);
    }
    printf("\n");

    if (dist[dst] >= INF)
    {
        printf("该两点不可达\n");
        return;
    }
    printf("该两点最短距离为：%d\n", dist[dst]);
    int tmp[MAXN], tp = 0;
    for (int v = dst; v != -1; v = pre[v])
    {
        tmp[tp++] = v;
    }
    printf("路径：");
    for (int i = tp - 1; i >= 0; i--)
    {
        printf("%s ", city[tmp[i]]);
    }
    printf("\n");
}
// ll vis[MAXN];
void dfs(ll x, ll fa)
{
    printf("%s ", idgetcity(x).c);
    for (int i = 1; i <= n; i++)
    {
        if (i == x || i == fa || ve[i][x] >= INF || visi[i])
        {
            continue;
        }
        visi[i] = 1;
        dfs(i, x);
    }
}
void op3()
{
    printf("请输入起点\n");
    char po[64];
    scanf("%s", po);
    ll cc = citygetid(po);
    visi[cc] = 1;
    printf("dfs序为：\n");
    dfs(cc, -1);
    printf("\n");
}
typedef struct HuffmanNode
{
    char c[64];
    int cnt;
    int weight;
    int de;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
    struct HuffmanNode *parent;
} HuffmanNode;
HuffmanNode **nodes = NULL;
void dfs2(HuffmanNode *x, int dfs_cnt)
{
    if (x->left != NULL)
    {
        x->left->de = 0;
        dfs2(x->left, dfs_cnt + 1);
    }
    if (x->right != NULL)
    {
        x->right->de = 1;
        dfs2(x->right, dfs_cnt + 1);
    }
    x->cnt = dfs_cnt;
}
void op4()
{
    printf("请输入数量\n");
    ll num;
    scanf("%lld", &num);
    ll tot = num + num - 1;

    nodes = (HuffmanNode **)malloc(tot * sizeof(HuffmanNode *));
    if (nodes == NULL)
    {
        printf("内存分配失败！\n");
        return;
    }

    for (int i = 0; i < tot; i++)
    {
        nodes[i] = (HuffmanNode *)malloc(sizeof(HuffmanNode));
        nodes[i]->c[0] = '\0';
        nodes[i]->weight = 0;
        nodes[i]->cnt = 0;
        nodes[i]->de = -1;
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
        nodes[i]->parent = NULL;
    }
    for (int i = num; i < tot; i++)
    {
        nodes[i]->weight = 0;
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
        nodes[i]->parent = NULL;
        nodes[i]->cnt = 0;
        nodes[i]->de = -1;
    }
    for (int i = 0; i < num; i++)
    {
        scanf("%s%d", nodes[i]->c, &nodes[i]->weight);
    }

    for (int i = num; i < tot; i++)
    {
        int m1 = -1, m2 = -1;

        for (int j = 0; j < i; j++)
        {
            if (nodes[j]->parent != NULL)
            {
                continue;
            }
            if (m1 == -1 || nodes[j]->weight < nodes[m1]->weight)
            {
                m1 = j;
            }
        }
        for (int j = 0; j < i; j++)
        {
            if (nodes[j]->parent != NULL || j == m1)
            {
                continue;
            }
            if (m2 == -1 || nodes[j]->weight < nodes[m2]->weight)
            {
                m2 = j;
            }
        }
        nodes[i]->left = nodes[m1];
        nodes[i]->right = nodes[m2];
        nodes[i]->weight = nodes[m1]->weight + nodes[m2]->weight;
        nodes[m1]->parent = nodes[i];
        nodes[m2]->parent = nodes[i];
    }
    // dfs
    int dfs_cnt = 0;
    dfs2(nodes[tot - 1], 1);

    // bfs
    HuffmanNode *q[1050];
    // queue
    int head = 0, tail = 0;
    q[tail++] = nodes[tot - 1];
    ll prc = 0;

    while (head < tail)
    {
        HuffmanNode *x = q[head++];
        if (x->cnt != prc)
        {
            printf("\n");
            prc = x->cnt;
        }
        if (x->c[0] == '\0')
        {
            printf("新节点 %d ", x->weight);
        }
        else
        {
            printf("%s %d ", x->c, x->weight);
        }
        if (x->de == 0)
        {
            printf("L    ");
        }
        else if (x->de == 1)
        {
            printf("R    ");
        }
        if (x->left != NULL)
        {
            q[tail++] = x->left;
        }
        if (x->right != NULL)
        {
            q[tail++] = x->right;
        }
    }
}
typedef struct AVLNode
{
    char c[64];
    int id, height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;
void op5()
{
    printf("请输入节点数量\n");
}
void solve()
{
    while (1)
    {
        printf("创建地图：1\n");
        printf("查询路线：2\n");
        printf("显示搜索路线：3\n");
        printf("城市名查询霍夫曼树：4\n");
        printf("城市名排序：5\n");
        printf("please input your task\n");
        ll op = 0;
        scanf("%ld", &op);
        if (op == 1)
        {
            op1();
        }
        else if (op == 2)
        {
            op2();
        }
        else if (op == 3)
        {
            op3();
        }
        else if (op == 4)
        {
            op4();
        }
        else if (op == 5)
        {
            op5();
            return;
        }
        else
        {
            printf("非法输入");
        }
    }
}
signed main()
{
    ll _ = 1;
    while (_--)
    {
        solve();
    }
    return 0;
}