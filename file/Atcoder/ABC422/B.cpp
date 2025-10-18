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
ll tx[] = {-1, 0, 1, 0};
ll ty[] = {0, -1, 0, 1};
void solve()
{
	cin >> n >> m;
	vector<vector<char>> a(n + 10, vector<char>(m + 10));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ll sum = 0;
			if (a[i][j] == '.')
			{
				continue;
			}
			for (int w = 0; w < 4; w++)
			{
				ll xx = i + tx[w];
				ll yy = j + ty[w];
				if (1 <= xx && xx <= n && 1 <= yy && yy <= m &&
					a[xx][yy] == '#')
				{
					sum++;
				}
			}
			if (sum == 3 || sum == 1 || sum == 0)
			{
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
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