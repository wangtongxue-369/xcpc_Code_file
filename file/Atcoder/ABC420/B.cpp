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
	vector<ll> ve(n + 10, 0);
	vector<string> s(n + 10);
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	for (int i = 1; i <= m; i++)
	{
		ll sum0 = 0, sum1 = 0;
		for (int j = 1; j <= n; j++)
		{
			if (s[j][i] == '0')
			{
				sum0++;
			}
			else
			{
				sum1++;
			}
		}

		if (sum0 == 0 || sum1 == 0)
		{
			for (int j = 1; j <= n; j++)
			{
				a[j]++;
			}
		}
		else if (sum0 < sum1)
		{
			for (int j = 1; j <= n; j++)
			{
				if (s[j][i] == '0')
				{
					a[j]++;
				}
			}
		}
		else
		{
			for (int j = 1; j <= n; j++)
			{
				if (s[j][i] == '1')
				{
					a[j]++;
				}
			}
		}
	}
	ll maxn = 0;
	for (int i = 1; i <= n; i++)
	{
		// cout << a[i] << ' ';
		maxn = max(maxn, a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == maxn)
		{
			cout << i << ' ';
		}
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