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
	cin >> n;
	vector<vector<ll>> ve(n + 10);
	ll u, v;
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	vector<ll> dist(n + 10);
	ll s1 = 1;
	function<void(ll x, ll fa)> dfs1 = [&](ll x, ll fa)
	{
		dist[x] = dist[fa] + 1;
		if (dist[s1] < dist[x])
		{
			s1 = x;
		}
		for (auto it : ve[x])
		{
			if (it != fa)
			{
				dfs1(it, x);
			}
		}
	};
	dfs1(1, 0);
	for (int i = 1; i <= n; i++)
	{
		if (dist[s1] <= dist[i])
		{
			s1 = i;
		}
	}
	dist.assign(n + 10, 0);
	ll s2 = s1;
	function<void(ll x, ll fa)> dfs2 = [&](ll x, ll fa)
	{
		dist[x] = dist[fa] + 1;
		if (dist[s2] < dist[x])
		{
			s2 = x;
		}
		for (auto it : ve[x])
		{
			if (it != fa)
			{
				dfs2(it, x);
			}
		}
	};
	dfs2(s1, 0);
	for (int i = 1; i <= n; i++)
	{
		if (dist[s2] <= dist[i])
		{
			s2 = i;
		}
	}
	if (s2 < s1)
	{
		swap(s1, s2);
	}
	vector<ll> dist1(n + 10, 0), dist2(n + 10, 0);
	function<void(ll x, ll fa)> dfs3 = [&](ll x, ll fa)
	{
		dist1[x] = dist1[fa] + 1;
		for (auto it : ve[x])
		{
			if (it != fa)
			{
				dfs3(it, x);
			}
		}
	};
	function<void(ll x, ll fa)> dfs4 = [&](ll x, ll fa)
	{
		dist2[x] = dist2[fa] + 1;
		for (auto it : ve[x])
		{
			if (it != fa)
			{
				dfs4(it, x);
			}
		}
	};
	dfs3(s1, 0);
	dfs4(s2, 0);
	for (int i = 1; i <= n; i++)
	{
		if (dist1[i] > dist2[i])
		{
			dist[i] = s1;
		}
		else
		{
			dist[i] = s2;
		}
		// dist[i] = max(dist[s1], dist[s2]);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << dist[i] << '\n';
	}
	cout << '\n';
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