#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll _;
	cin >> _;
	while (_--)
	{
		int n;
		if (!(cin >> n))
			return 0;
		vector<int> L(n + 1), R(n + 1);
		for (int i = 1; i <= n; i++)
		{
			int a, b;
			cin >> a >> b;
			L[i] = a;
			R[i] = b;
		}
		// Precompute minNodes[h] : minimal nodes in an AVL tree of height h
		const int HMAX = 60; // safe upper bound
		vector<long long> minNodes(HMAX + 1, 0);
		minNodes[0] = 0;
		if (HMAX >= 1)
			minNodes[1] = 1;
		for (int h = 2; h <= HMAX; ++h)
		{
			// recurrence: minNodes[h] = 1 + minNodes[h-1] + minNodes[h-2]
			minNodes[h] = 1 + minNodes[h - 1] + minNodes[h - 2];
			// Cap to avoid overflow (more than n is enough)
			if (minNodes[h] > (1LL << 60))
				minNodes[h] = (1LL << 60);
		}

		// compute subtree sizes and order (postorder)
		vector<int> st;
		st.reserve(n);
		vector<int> parent(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			if (L[i])
				parent[L[i]] = i;
			if (R[i])
				parent[R[i]] = i;
		}
		int root = 1; // problem statement root is 1
		// compute sizes, get postorder by stack
		vector<int> ord;
		ord.reserve(n);
		vector<int> vis(n + 1, 0);
		// iterative postorder
		vector<int> stackv;
		stackv.push_back(root);
		while (!stackv.empty())
		{
			int u = stackv.back();
			if (vis[u] == 0)
			{
				vis[u] = 1;
				if (L[u])
					stackv.push_back(L[u]);
				if (R[u])
					stackv.push_back(R[u]);
			}
			else
			{
				stackv.pop_back();
				ord.push_back(u);
			}
		}
		vector<int> sz(n + 1, 0);
		for (int u : ord)
		{
			sz[u] = 1;
			if (L[u])
				sz[u] += sz[L[u]];
			if (R[u])
				sz[u] += sz[R[u]];
		}
		for (int i = 1; i <= n; i++)
		{
			cout <<
		}

		// DP: dp[u][h] for h=0..HMAX
		// We'll store as vector<vector<int>> but costs may exceed int => use int64
		const long long BIG = (1LL << 60);
		vector<vector<long long>> dp(n + 1, vector<long long>(HMAX + 1, BIG));
		// For missing child (0), we will not have dp[0], but treat empty:
		// cost to make missing child height t is minNodes[t] (creating that many nodes)
		// For existing node u: dp[u][0] = sz[u] (delete entire subtree)
		for (int u : ord)
		{
			dp[u][0] = sz[u]; // delete entire subtree
			// compute for h>=1
			for (int h = 1; h <= HMAX; ++h)
			{
				long long best = BIG;
				// possible (L,R) combos:
				// (h-1,h-1), (h-1,h-2), (h-2,h-1) -- skip negative indices
				vector<pair<int, int>> pairs;
				pairs.emplace_back(h - 1, h - 1);
				if (h - 2 >= 0)
				{
					pairs.emplace_back(h - 1, h - 2);
					pairs.emplace_back(h - 2, h - 1);
				}
				for (auto pr : pairs)
				{
					int HL = pr.first, HR = pr.second;
					long long costL, costR;
					if (L[u])
					{
						costL = dp[L[u]][HL];
					}
					else
					{
						// missing child, need to create a subtree of height HL: cost = minNodes[HL]
						if (HL <= HMAX)
							costL = minNodes[HL];
						else
							costL = BIG;
					}
					if (R[u])
					{
						costR = dp[R[u]][HR];
					}
					else
					{
						if (HR <= HMAX)
							costR = minNodes[HR];
						else
							costR = BIG;
					}
					if (costL >= BIG || costR >= BIG)
						continue;
					long long cand = costL + costR;
					if (cand < best)
						best = cand;
				}
				dp[u][h] = best;
			}
		}

		// answer: min over dp[root][h] and deleting entire tree
		long long ans = sz[root]; // delete all
		for (int h = 0; h <= HMAX; ++h)
		{
			if (dp[root][h] < ans)
				ans = dp[root][h];
		}
		cout << ans << "\n";
	}

	return 0;
}
