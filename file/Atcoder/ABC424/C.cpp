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
	cin >> n;
	vector<vector<ll>> ve(n + 10);
	vector<ll> vis(n + 10);
	queue<ll> q;
	for (int i = 1; i <= n; i++)
	{
		ll u, v;
		cin >> u >> v;
		if (u == 0 && v == 0)
		{
			vis[i] = 1;
			ans++;
			q.push(i);
		}
		else
		{
			ve[u].push_back(i);
			ve[v].push_back(i);
		}
	}
	while (!q.empty())
	{
		auto x = q.front();
		q.pop();
		for (auto it : ve[x])
		{
			if (vis[it])
			{
				continue;
			}
			else
			{
				ans++;
				vis[it] = 1;
				q.push(it);
			}
		}
	}
	cout << ans << '\n';
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