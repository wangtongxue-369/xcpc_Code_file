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
ll _ = 1, n, m, ans = 0, f[2050][2050];
void solve()
{
	string a, b;
	cin >> a >> b;
	n = a.length();
	m = b.length();

	for (int i = 0; i <= n; i++)
	{
		f[i][0] = i;
	}
	for (int j = 0; j <= m; j++)
	{
		f[0][j] = j;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				f[i][j] = f[i - 1][j - 1];
				continue;
			}
			f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
			// cout << f[i][j] << '\n';
		}
	}
	cout << f[n][m] << '\n';
}
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
