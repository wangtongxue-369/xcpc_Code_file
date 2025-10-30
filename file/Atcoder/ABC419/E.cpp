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
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
void solve()
{
	ll l;
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] %= m;
	}
	vector<vector<ll>> f(510, vector<ll>(510, 0));
	for (int i = 1; i <= l; i++)
	{
		for (int x = 0; x < m; x++)
		{
			for (int j = i; j <= n; j += l)
			{
				if (a[j] <= x)
				{
					f[i][x] += x - a[j];
				}
				else
				{
					f[i][x] += m - abs(a[j] - x);
				}
			}
		}
	}

	vector<vector<ll>> dp(510, vector<ll>(510, INF));
	for (int i = 0; i < m; i++)
	{
		dp[1][i] = f[1][i];
	}
	for (int i = 2; i <= l; i++)
	{
		for (int s1 = 0; s1 < m; s1++)
		{
			for (int s2 = 0; s2 < m; s2++)
			{
				dp[i][(s1 + s2) % m] = min(dp[i][(s1 + s2) % m], dp[i - 1][s1] + f[i][s2]);
			}
		}
	}
	cout << dp[l][0] << '\n';
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