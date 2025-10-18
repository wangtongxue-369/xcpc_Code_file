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
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	ll u, v;
	vector<ll> dist(n + 10, 2e18);
	vector<vector<ll>> ve(n + 10);
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	vector<ll> dis(n + 10, 1e18);
	dis[1] = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		vector<ll> disn = dis;
		for (int u = 1; u <= n; u++)
		{
			if (disn[u] == 1e18)
			{
				continue;
			}
			for (auto it : ve[u])
			{
				disn[it] = min(disn[it], dis[u] + i * a[u]);
			}
		}
		dis = disn;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << '\n';
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