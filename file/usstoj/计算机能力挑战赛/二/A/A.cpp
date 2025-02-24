#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0; // a[500005], f[500005];
ll dp[1010][100];
struct node
{
	ll t, v;
} a[110];
void solve()
{
	ll t, m;
	cin >> t >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].t >> a[i].v;
	}
	ans = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = t; j >= 0; j--)
		{
			if (j >= a[i].t)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].t] + a[i].v);
				// ans = max(ans, dp[i][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[m][t] << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin>>_;
	while (_--)
	{
		solve();
	}
	return 0;
}
