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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
	cin >> n >> m;
	vector<vector<bool>> ve(1024, vector<bool>(1024, 0));
	vector<vector<ll>> dp(n + 10, vector<ll>(1024, INF));
	dp[0][0] = 0;
	vector<ll> a(n + 10);
	ll k = (1ll << m);
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		ll t = 0;
		for (int j = 0; j < m; j++)
		{
			t += (1ll << j) * (s[j] == '#');
		}
		a[i] = t;
	}

	for (ll i = 0; i < k; i++)
	{
		for (ll j = 0; j < k; j++)
		{
			ve[i][j] = 1;
			ll t = i & j;
			for (ll w = 0; w < m - 1; w++)
			{
				if ((t >> w & 3) == 3)
				{
					ve[i][j] = 0;
					break;
				}
			}
		}
	}

	for (ll i = 1; i <= n; i++)
	{
		// dp[i][0] = 0;
		for (ll j = 0; j < k; j++)
		{
			if ((j | a[i]) == a[i])
			{
				for (ll jj = 0; jj < k; jj++)
				{
					if (ve[j][jj])
					{
						dp[i][j] = min(dp[i][j], dp[i - 1][jj] + __builtin_popcountll(j ^ a[i]));
					}
				}
			}
		}
	}
	ans = INF;
	for (int i = 0; i < k; i++)
	{
		ans = min(ans, dp[n][i]);
	}
	cout << ans << '\n';
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