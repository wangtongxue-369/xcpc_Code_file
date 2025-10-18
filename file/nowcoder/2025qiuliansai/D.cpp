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
	string s;
	cin >> s;
	s = ' ' + s;
	ll u, v;
	vector<vector<ll>> ve(n + 10);
	vector<ll> dep(n + 10, 0);
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	function<ll(ll x, ll fa)> dfs = [&](ll x, ll fa)
	{
		ll sum = 0;
		sum++;
		for (auto it : ve[x])
		{
			if (it == fa || s[it] == 'B')
			{
				continue;
			}
			if (s[it] == 'W')
			{
				sum += dfs(it, x);
			}
		}
		return sum;
	};
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 'B')
		{
			vector<ll> vee;
			for (auto it : ve[i])
			{
				if (s[it] == 'B')
				{
					continue;
				}
				vee.push_back(dfs(it, i));
			}
			for (int s1 = 0; s1 < vee.size(); s1++)
			{
				// cout << vee[s1] << ' ';
				ans += vee[s1];
				for (int s2 = s1 + 1; s2 < vee.size(); s2++)
				{

					ans += vee[s1] * vee[s2];
				}
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