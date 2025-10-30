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
#define ll long long
#define ull unsigned long long
#define ld long double
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
	cin >> n >> m;
	ll u, v;
	vector<vector<ll>> ve(n + 10);
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	string s;
	cin >> s;
	s = ' ' + s;
	queue<array<ll, 3>> q;
	vector<PII> dis(n + 10);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 'S')
		{
			q.push({i, 0});
		}
	}
	while (!q.empty())
	{
		auto [x, dist, root] = q.front();
		q.pop();

		for (auto it : ve[x])
		{
			if (dis[it].first)
			{
				continue;
			}
			q.push({it, dist + 1, root});
			dis[it] = {dist + 1, root};
		}
	}
	// for (int i = 1; i <= n; i++)
	// {
	// cout << dis[i] << ' ';
	// }
	function<bool(ll s1, ll s2)> cmp = [&](ll s1, ll s2)
	{
		return dis[s1] < dis[s2];
	};
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 'D')
		{
			ll sum = 0;
			for (auto it : ve[i])
			{
				if (s[it] == 'S')
				{
					sum++;
				}
			}
			if (sum >= 2)
			{
				cout << 2 << '\n';
				continue;
			}
			if (ve[i].size() == 1)
			{
				cout << dis[ve[i][0]].first + dis[i].first + 1 << '\n';
				continue;
			}
			sort(ve[i].begin(), ve[i].end(), cmp);

			cout << dis[i].first + dis[ve[i][0]].first + 1 << '\n';
		}
	}
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