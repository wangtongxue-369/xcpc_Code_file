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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
	ll st, en;
	cin >> n >> st >> en;
	vector<vector<ll>> ve(n + 10);
	ll u, v;
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	if (n == 1)
	{
		cout << 1 << '\n';
		return;
	}
	vector<bool> vis(n + 10, 0);
	vector<PII> s;
	// dep[en] = 1;
	queue<PII> q;
	q.push({en, 1});
	vis[en] = 1;
	s.push_back({en, 1});
	ll x;

	while (q.size())
	{
		auto [x, y] = q.front();
		q.pop();
		for (auto it : ve[x])
		{
			if (vis[it])
			{
				continue;
			}
			vis[it] = 1;
			s.push_back({it, y + 1});
			q.push({it, y + 1});
		}
	}
	function<bool(PII s1, PII s2)> cmp = [](PII s1, PII s2)
	{
		return s1.second > s2.second;
	};
	sort(s.begin(), s.end(), cmp);
	for (auto it : s)
	{
		cout << it.first << ' ';
	}
	cout << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> _;
	while (_--)
	{
		solve();
	}
	return 0;
}
