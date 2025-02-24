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
ll _ = 1, n, m, ans = 0, a[MAXN], f[300][10];
void solve()
{
	ll k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		f[i][1] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int x = 2; x <= k; x++)
		{
			if (i > x)
			{
				f[i][x] = f[i - x][x] + f[i - 1][x - 1];
			}
			else
			{
				f[i][x] = f[i - 1][x - 1];
			}
		}
	}
	cout << f[n][k] << '\n';
}
// 枚举dp[n][k] k拆为x和k-x
// dp[i][j]    j>i 无法分 dp[i][j]=0
//             j==i  dp[i][j]=1
// dp[i][j]=dp[i][j]
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cin>>_;
	while (_--)
	{
		solve();
	}
	return 0;
}
