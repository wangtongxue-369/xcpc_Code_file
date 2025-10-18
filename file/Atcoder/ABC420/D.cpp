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
	vector<vector<array<ll, 3>>> dist(n + 10, vector<array<ll, 3>>(m + 10, {INF, INF, INF}));
	ll sx = 0, sy = 0;
	ll ex = 0, ey = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'S')
			{
				sx = i, sy = j;
			}
			if (a[i][j] == 'G')
			{
				ex = i, ey = j;
			}
		}
	}
	queue<array<ll, 4>> q;
	q.push({0, sx, sy, 0});
	dist[sx][sy][0] = 0;
	while (!q.empty())
	{
		auto [c, x, y, is] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			ll xx = x + tx[i];
			ll yy = y + ty[i];
			ll nis = is;
			if (1 <= xx && xx <= n && 1 <= yy && yy <= m && a[xx][yy] != '#')
			{
				if (a[xx][yy] == 'o')
				{
					if (is == 1)
					{
						continue;
					}
				}
				if (a[xx][yy] == 'x')
				{
					if (is == 0)
					{
						continue;
					}
				}
				if (dist[xx][yy][is] != INF)
				{
					continue;
				}
				if (a[xx][yy] == '?')
				{
					nis = !is;
				}
				dist[xx][yy][is] = c + 1;
				q.push({c + 1, xx, yy, nis});
			}
		}
	}
	ll x = min(dist[ex][ey][0], dist[ex][ey][1]);
	if (x == INF)
	{
		cout << -1 << '\n';
		return;
	}
	cout << x << '\n';
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