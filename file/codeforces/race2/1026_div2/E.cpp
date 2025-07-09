#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 5;

int t, n;
map<int, int> vol_id, pitch_id;
vector<pair<int, int>> sounds;            // {volume, pitch}
vector<tuple<int, int, int>> graph[MAXN]; // {to, edge_id, direction: 0=vol->pitch}
vector<bool> used;
vector<int> answer;
int id_cnt;

void reset()
{
    vol_id.clear();
    pitch_id.clear();
    sounds.clear();
    used.clear();
    answer.clear();
    for (int i = 0; i < MAXN; ++i)
        graph[i].clear();
    id_cnt = 0;
}

void dfs(int u)
{
    while (!graph[u].empty())
    {
        auto [v, eid, dir] = graph[u].back();
        graph[u].pop_back();
        if (used[eid])
            continue;
        used[eid] = true;
        dfs(v);
        answer.push_back(eid);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        reset();
        sounds.resize(n);

        int vid = 0, pid = 0;
        for (int i = 0; i < n; ++i)
        {
            int v, p;
            cin >> v >> p;
            sounds[i] = {v, p};
            if (!vol_id.count(v))
                vol_id[v] = vid++;
            if (!pitch_id.count(p))
                pitch_id[p] = pid++;
        }

        int offset = vid; // pitch id starts from vid
        int total_nodes = vid + pid;

        used.resize(n, false);

        // build graph
        for (int i = 0; i < n; ++i)
        {
            int v = vol_id[sounds[i].first];
            int p = pitch_id[sounds[i].second] + offset;
            graph[v].emplace_back(p, i, 0);
            graph[p].emplace_back(v, i, 1);
        }

        // check degree
        vector<int> odd_nodes;
        for (int i = 0; i < total_nodes; ++i)
        {
            if (graph[i].size() % 2 == 1)
                odd_nodes.push_back(i);
        }

        if (odd_nodes.size() != 0 && odd_nodes.size() != 2)
        {
            cout << "NO\n";
            continue;
        }

        int start = 0;
        if (!odd_nodes.empty())
            start = odd_nodes[0];
        else
        {
            // find a non-isolated node
            for (int i = 0; i < total_nodes; ++i)
            {
                if (!graph[i].empty())
                {
                    start = i;
                    break;
                }
            }
        }

        dfs(start);

        if ((int)answer.size() != n)
        {
            cout << "NO\n";
            continue;
        }

        reverse(answer.begin(), answer.end());
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
            cout << answer[i] + 1 << " ";
        cout << "\n";
    }
    return 0;
}
