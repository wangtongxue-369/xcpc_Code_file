#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

const int MOD = 998244353;
const int INF = 1e9;

vector<vector<int>> adj;
vector<int> in_time, out_time, depth;
int timer = 0;

void dfs(int node, int parent)
{
    in_time[node] = timer++;
    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;
        depth[neighbor] = depth[node] + 1;
        dfs(neighbor, node);
    }
    out_time[node] = timer - 1;
}

inline bool in_subtree(int node, int rep)
{
    return in_time[rep] <= in_time[node] && in_time[node] <= out_time[rep];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    in_time.resize(n + 1);
    out_time.resize(n + 1);
    depth.resize(n + 1, -1);
    depth[1] = 0;
    timer = 0;
    dfs(1, 0);

    vector<int> critical_indices(m);
    for (int i = 0; i < m; i++)
    {
        cin >> critical_indices[i];
        critical_indices[i]--;
    }

    vector<pair<int, int>> critical_edges;
    for (int idx : critical_indices)
    {
        critical_edges.push_back(edges[idx]);
    }

    vector<int> rep_node(m);
    for (int i = 0; i < m; i++)
    {
        int u = critical_edges[i].first;
        int v = critical_edges[i].second;
        if (depth[u] > depth[v])
        {
            rep_node[i] = u;
        }
        else
        {
            rep_node[i] = v;
        }
    }

    vector<int> global_cnt(1 << m, 0);
    int full_mask = (1 << m) - 1;

    for (int i = 0; i < k; i++)
    {
        int s, t;
        cin >> s >> t;
        int mask = 0;
        for (int j = 0; j < m; j++)
        {
            bool s_in = in_subtree(s, rep_node[j]);
            bool t_in = in_subtree(t, rep_node[j]);
            if (s_in != t_in)
            {
                mask |= (1 << j);
            }
        }
        global_cnt[mask]++;
    }

    int overall_or = 0;
    for (int mask = 0; mask < (1 << m); mask++)
    {
        if (global_cnt[mask] > 0)
        {
            overall_or |= mask;
        }
    }
    if (overall_or != full_mask)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<long long> sos_cnt(1 << m, 0);
    for (int mask = 0; mask < (1 << m); mask++)
    {
        sos_cnt[mask] = global_cnt[mask];
    }
    for (int i = 0; i < m; i++)
    {
        for (int state = full_mask; state >= 0; state--)
        {
            if (state & (1 << i))
                continue;
            sos_cnt[state] += sos_cnt[state | (1 << i)];
        }
    }

    vector<pair<int, long long>> reduced;
    for (int mask = 0; mask < (1 << m); mask++)
    {
        if (global_cnt[mask] == 0)
            continue;
        if (sos_cnt[mask] - global_cnt[mask] > 0)
        {
            continue;
        }
        reduced.push_back({mask, global_cnt[mask]});
    }

    vector<int> dp(1 << m, INF);
    vector<long long> g(1 << m, 0);
    dp[0] = 0;
    g[0] = 1;

    for (auto &p : reduced)
    {
        int mask = p.first;
        long long cnt = p.second;
        for (int state = 0; state < (1 << m); state++)
        {
            if (dp[state] == INF)
                continue;
            int new_state = state | mask;
            int new_count = dp[state] + 1;
            long long new_ways = g[state] * cnt % MOD;
            if (new_count < dp[new_state])
            {
                dp[new_state] = new_count;
                g[new_state] = new_ways;
            }
            else if (new_count == dp[new_state])
            {
                g[new_state] = (g[new_state] + new_ways) % MOD;
            }
        }
    }

    if (dp[full_mask] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[full_mask] << " " << g[full_mask] % MOD << endl;
    }

    return 0;
}