#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to compute mex of a vector of integers
int compute_mex(const vector<int> &vec)
{
    unordered_set<int> s(vec.begin(), vec.end());
    int mex = 0;
    while (s.find(mex) != s.end())
        mex++;
    return mex;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        // Build adjacency list
        vector<vector<int>> adj(n + 1, vector<int>());
        for (int i = 1; i <= n; i++)
        {
            adj[i].push_back(i == 1 ? n : i - 1);
            adj[i].push_back(i == n ? 1 : i + 1);
        }
        // Add chord
        adj[x].push_back(y);
        adj[y].push_back(x);
        // Initialize labels
        vector<int> a(n + 1, -1);
        // Assign a[x]=0, a[y]=1
        a[x] = 0;
        a[y] = 1;
        // Initialize queue
        queue<int> q;
        q.push(x);
        q.push(y);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &v : adj[u])
            {
                if (a[v] == -1)
                {
                    // Collect labels of neighbors
                    vector<int> labels;
                    for (auto &nei : adj[v])
                    {
                        if (a[nei] != -1)
                        {
                            labels.push_back(a[nei]);
                        }
                    }
                    // Compute mex
                    int mex = 0;
                    unordered_set<int> s(labels.begin(), labels.end());
                    while (s.find(mex) != s.end())
                        mex++;
                    a[v] = mex;
                    q.push(v);
                }
            }
        }
        // Assign 0 to any remaining nodes
        for (int i = 1; i <= n; i++)
            if (a[i] == -1)
                a[i] = 0;
        // Output
        for (int i = 1; i <= n; i++)
            cout << a[i] << (i < n ? " " : "\n");
    }
}
