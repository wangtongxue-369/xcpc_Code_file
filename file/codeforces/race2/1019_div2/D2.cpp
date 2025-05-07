#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vi a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        // 1) rem_round: 实际的“删除轮次”，把 a[i]==-1 作为 max_round+1
        int max_round = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > max_round)
                max_round = a[i];
        }
        vi rem_round(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == -1)
                rem_round[i] = max_round + 1;
            else
                rem_round[i] = a[i];
        }
        // 2) 按轮次收集本轮要删除的下标
        vector<vi> group(max_round + 2);
        for (int i = 1; i <= n; i++)
        {
            group[rem_round[i]].push_back(i);
        }

        // 3) 构造约束图：u->v 表示 p[u] < p[v]
        vector<vi> adj(n + 1);
        vi indeg(n + 1, 0);

        // alive_prev 存活下标列表，初始为 1..n
        vi alive_prev(n);
        iota(alive_prev.begin(), alive_prev.end(), 1);

        // 按 k=1..max_round 逐轮添加边
        for (int k = 1; k <= max_round; k++)
        {
            int L = alive_prev.size();
            // pos_in_alive[i] = i 在 alive_prev 中的位置
            vi pos_in_alive(n + 1, -1);
            for (int i = 0; i < L; i++)
            {
                pos_in_alive[alive_prev[i]] = i;
            }
            // 1) 幸存者 rem_round>k 要作局部极小(odd)或极大(even)
            for (int idx = 0; idx < L; idx++)
            {
                int u = alive_prev[idx];
                if (rem_round[u] <= k)
                    continue; // 本轮不幸存
                // 寻左右相邻
                if (idx > 0)
                {
                    int v = alive_prev[idx - 1];
                    if (k & 1)
                    {
                        // odd round: survivor must be local minimum => p[u] < p[v]
                        adj[u].push_back(v);
                    }
                    else
                    {
                        // even round: survivor must be local maximum => p[u] > p[v] => p[v] < p[u]
                        adj[v].push_back(u);
                    }
                }
                if (idx + 1 < L)
                {
                    int v = alive_prev[idx + 1];
                    if (k & 1)
                    {
                        adj[u].push_back(v);
                    }
                    else
                    {
                        adj[v].push_back(u);
                    }
                }
            }
            // 2) 本轮删除者 rem_round==k，只需与一个相邻节点建立反向约束
            for (int u : group[k])
            {
                int pos = pos_in_alive[u];
                int cand = -1;
                // 考虑左右哪个 rem_round 更大，优先幸存者
                if (pos > 0 && pos + 1 < L)
                {
                    int l = alive_prev[pos - 1], r = alive_prev[pos + 1];
                    cand = (rem_round[l] >= rem_round[r] ? l : r);
                }
                else if (pos > 0)
                {
                    cand = alive_prev[pos - 1];
                }
                else if (pos + 1 < L)
                {
                    cand = alive_prev[pos + 1];
                }
                if (cand == -1)
                    continue; // 理论上不会出现
                if (k & 1)
                {
                    // odd round: 删除者非极小 => p[u] > p[cand] => p[cand] < p[u]
                    adj[cand].push_back(u);
                }
                else
                {
                    // even round: 删除者非极大 => p[u] < p[cand] => p[u] < p[cand]
                    adj[u].push_back(cand);
                }
            }
            // 3) 更新 alive_prev，剔除本轮删除者
            vi next_alive;
            next_alive.reserve(L);
            for (int u : alive_prev)
            {
                if (rem_round[u] > k)
                    next_alive.push_back(u);
            }
            alive_prev.swap(next_alive);
        }

        // 4) 拓扑排序
        // 先算入度
        for (int u = 1; u <= n; u++)
        {
            for (int v : adj[u])
            {
                indeg[v]++;
            }
        }
        deque<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (indeg[i] == 0)
                q.push_back(i);
        }
        vi order;
        order.reserve(n);
        while (!q.empty())
        {
            int u = q.front();
            q.pop_front();
            order.push_back(u);
            for (int v : adj[u])
            {
                if (--indeg[v] == 0)
                    q.push_back(v);
            }
        }
        // 一定能排序完毕，否则题目保证有解
        // 5) 赋值 p
        vi p(n + 1);
        for (int i = 0; i < n; i++)
        {
            p[order[i]] = i + 1;
        }
        // 输出
        for (int i = 1; i <= n; i++)
        {
            cout << p[i] << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}
